/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#include <osbind.h>
#include <stdio.h>
#include "menu.h"

int MENU_STATE = 1;
bool CLICK_IS_VALID = false;

UINT16 menuPointer[16] = 
{
	0xffff,
	0xffff,
	0x001f,
	0x000f,
	0x0007,
	0x0003,
	0x0001,
	0x0000,
	0x0000,
	0x0001,
	0x0003,
	0x0007,
	0x000f,
	0x001f,
	0xffff,
	0xffff
};

void menu() 
{
	unsigned long input;
	int option = 1;
	int previousOption = option;
	int mouseOption;
	int previousMouseOption;
	UINT16 *base = get_video_base();

	initializeMouse(base);

	drawKeyboardArrow(option, base);
	
	while (MENU_STATE != 3) 
	{
		updateMouse(base);
		if (ikbdWaiting()) 
		{
			clearKeyboardArrow(mouseOption, base);
			previousOption = option;
			input = readFromBuffer();
			if(input == UP_KEY)
			{
				if(option > 1)
				{
					option = option - 1;
				}
			}
			else if (input == DOWN_KEY)
			{
				if(option < 3)
				{
					option = option + 1;
				}
			}
			clearKeyboardArrow(previousOption, base);
			drawKeyboardArrow(option, base);

			if (input == ENTER_KEY)
			{
				selectOption(option);
			}
			if (input == ESC_KEY)
			{
				selectOption(3);
			}

		} 
		else if (ikbdMouseMoved()) 
		{
			previousMouseOption = mouseOption;
			mouseOption = mouseLocation();
			if (mouseOption != INVALID_MOUSEOPTION) 
			{
				if (CLICK_IS_VALID && MOUSE_LEFT_CLICK)
				{
					selectOption(mouseOption);
				}
			}
		}
  }
}

void selectOption(int option) 
{
	if(option == 1)
	{
		MENU_STATE = 3; /*Exits menu and goes to game*/
		game_loop();
	}
	else if (option == 2)
	{
		/*Implement for 2 player*/
	}
	else
	{
		MENU_STATE = 3;
	}
}


void drawKeyboardArrow(int option, UINT16* base) 
{
	if(option == 1)
	{
		plot_bitmap_menu(base, SELECTION_X, SELECTION_1PLAYERY, menuPointer,16);
	}
	else if(option == 2)
	{
		plot_bitmap_menu(base, SELECTION_X, SELECTION_2PLAYERY, menuPointer,16);
	}
	else if (option == 3)
	{
		plot_bitmap_menu(base, SELECTION_X, SELECTION_QUIT_Y, menuPointer, 16);
	}
}

void clearKeyboardArrow(int option, UINT16* base) 
{
	if(option == 1)
	{
		clearRegion(base, SELECTION_X, SELECTION_1PLAYERY, 16, 16);
	}
	else if(option == 2)
	{
		clearRegion(base, SELECTION_X, SELECTION_2PLAYERY, 16, 16);
	}
	else if (option == 3)
	{
		clearRegion(base, SELECTION_X, SELECTION_QUIT_Y, 16, 16);
	}

}

int mouseLocation() 
{
	bool valid_x = false;
	bool valid_y_option1 = false;
	bool valid_y_option2 = false;
	bool valid_y_option3 = false;
	int mouseLocation = false;
   
	mouseLocation = INVALID_MOUSEOPTION;
  
	if(MOUSE_X >= 210 && MOUSE_X <= 320)
	{
		valid_x = true;
	}
	
	if(MOUSE_Y >= 170 && MOUSE_Y <= 210)
	{
		valid_y_option1 = true;
	}
	else if(MOUSE_Y >= 215 && MOUSE_Y <= 245)
	{
		valid_y_option2 = true;
	}
	else if(MOUSE_Y >= 250 && MOUSE_Y <= 290)
	{
		valid_y_option3 = true;
	}

	if (valid_x && valid_y_option1)
	{
		mouseLocation = 1;
	}
	else if (valid_x && valid_y_option2)
	{
		mouseLocation = 2;
	}
	else if (valid_x && valid_y_option3)
	 {
		mouseLocation = 3;
	 }

	if((valid_x && valid_y_option1) ||(valid_x && valid_y_option2) || (valid_x && valid_y_option3))
	{
		CLICK_IS_VALID = true;
	}

  return mouseLocation;
}
