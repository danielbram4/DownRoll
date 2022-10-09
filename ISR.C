/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#include "isr.h"

int MUSIC_TIMER = 0;
int GAME_TIMER = 0;
bool RENDER_REQUEST = true;
bool RENDER_MOUSE_REQUEST = false;

volatile UINT8* const ASCII_TABLE = ASCII_ADDRESS;

volatile UINT8* const IKBD_CONTROL = IKBD_ADDRESS;
volatile UINT8* const IKBD_STATUS = IKBD_ADDRESS;
volatile UINT8* const IKBD_RDR = IKBD_RDR_ADDRESS;
volatile UINT8* const ISRB_MFP_REGISTER = MFP_ADDRESS;

UINT8 ikbdBuffer[IKBDBUFFERSIZE];
unsigned int buff_head = 0;
unsigned int buff_tail = 0;

int mouse_state = 0;
UINT8 mouse_button;
UINT8 mouse_delta_x;
UINT8 mouse_delta_y;
bool mouse_moved = false;

int MOUSE_X = 0;
int MOUSE_Y = 0;
bool MOUSE_LEFT_CLICK = false;
int prev_mouse_x = 0;
int prev_mouse_y = 0;

Vector vbl_vector;
Vector ikbd_vector;

void do_vbl_isr() 
{
	MUSIC_TIMER++;
	GAME_TIMER++;
	RENDER_REQUEST = true;
	RENDER_MOUSE_REQUEST = true;
}

void do_ikbd_isr() 
{
	UINT8 scancode;
	bool moved = false;
	bool status = false;
	*IKBD_CONTROL = 0x16;
	status = *IKBD_STATUS & STATUS_MASK;
	if (status) 
	{
		scancode = *IKBD_RDR;
		if (mouse_state == MOUSE_STATE_FIRST_PACKET) 
		{
			if (scancode >= MOUSE_MOVE_CODE) 
			{
				mouse_button = scancode;
				mouse_state = MOUSE_STATE_DELTA_X;
				if(scancode == MOUSE_MOVE_CODE)
				{
					moved = true;
				}
				mouse_moved = moved;
			} 
			else if ((scancode & BREAK_CODE_MASK) == 0x00) 
			{ 
				writeToBuffer(scancode);
			} 
		} 
		else if (mouse_state == MOUSE_STATE_DELTA_X)
		{ 
		  mouse_state = MOUSE_STATE_DELTA_Y;
		  mouse_delta_x = scancode;
		}
		else if (mouse_state == MOUSE_STATE_DELTA_Y) 
		{ 
		  mouse_state = MOUSE_STATE_FIRST_PACKET;
		  mouse_delta_y = scancode;
		}

		*ISRB_MFP_REGISTER &= MFB_BIT_6_MASK_OFF; 
	}

	*IKBD_CONTROL = 0x96;
}

void initializeMouse(UINT16* base) 
{
	MOUSE_X = MOUSE_START_X;
	MOUSE_Y = MOUSE_START_Y;
	prev_mouse_x = MOUSE_X;
	prev_mouse_y = MOUSE_Y;
	saveMouseBackGround(base, MOUSE_X, MOUSE_Y);
	renderMousePointer(base, MOUSE_X, MOUSE_Y);
}

void updateMouse(UINT16* base) 
{
	bool leftClick = false;

	MOUSE_X = MOUSE_X + (int)((char)mouse_delta_x);
	MOUSE_Y = MOUSE_Y + (int)((char)mouse_delta_y);

	if (MOUSE_X < 0)
	{
		MOUSE_X = 0;
	}
	else if (MOUSE_X > 620)
	{
		MOUSE_X = 620;
	}
	if (MOUSE_Y < 0)
	{
		MOUSE_Y = 0;
	}
	else if (MOUSE_Y > 380)
	{
		MOUSE_Y = 380;
	}
	
	if(mouse_button == MOUSE_LEFT_BUTTON_CODE)
	{
		leftClick = true;
	}
	MOUSE_LEFT_CLICK = leftClick;

	mouse_delta_x = 0;
	mouse_delta_y = 0;
	if (RENDER_MOUSE_REQUEST) 
	{
		clearRegion(base, prev_mouse_x, prev_mouse_y, 8, 8);
		restoreMouseBackGround(base, prev_mouse_x, prev_mouse_y);
		saveMouseBackGround(base, MOUSE_X, MOUSE_Y);
		renderMousePointer(base, MOUSE_X, MOUSE_Y);

		prev_mouse_x = MOUSE_X;
		prev_mouse_y = MOUSE_Y;

		RENDER_MOUSE_REQUEST = false;
	}
}

void install_vectors() 
{
	vbl_vector = install_vector(VBL_ISR, vbl_isr);
	ikbd_vector = install_vector(IKBD_ISR, ikbd_isr);
}

void remove_vectors() 
{
	install_vector(VBL_ISR, vbl_vector);
	install_vector(IKBD_ISR, ikbd_vector);
}

Vector install_vector(int num, Vector vector) 
{
	Vector* vectp = (Vector *) ((long) num << 2);
	Vector orig;
	long old_ssp = Super(0);

	orig = *vectp;
	*vectp = vector;

	Super(old_ssp);
	return orig;
}

bool ikbdWaiting() 
{
	bool waiting = buff_head != buff_tail;
	return waiting;
}

bool ikbdMouseMoved() 
{
	bool moved = mouse_moved;
	return moved;
}

void writeToBuffer(UINT8 scancode) 
{
	if (buff_tail == IKBDBUFFERSIZE - 1)
	{
		buff_tail = 0;
	}
	ikbdBuffer[buff_tail] = scancode;
	buff_tail++;
}

unsigned long readFromBuffer() 
{
	unsigned long input;
	long old_ssp = Super(0);

	if (buff_head == IKBDBUFFERSIZE - 1)
	{
		buff_head = 0;
	}

	*ISRB_MFP_REGISTER &= MFB_BIT_6_MASK_OFF;

	input = ikbdBuffer[buff_head];
	input = input << 16;
	input = input + *(ASCII_TABLE + ikbdBuffer[buff_head++]);

	*ISRB_MFP_REGISTER |= MFB_BIT_6_MASK_ON;

	Super(old_ssp);
	return input;
}

void clearBuffer() 
{
	while(ikbdWaiting()) 
	{
		buff_head++;
	}

	ikbdBuffer[buff_tail] = 0x00;
}

