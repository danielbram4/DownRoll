/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef DOWNROLL_INTERRUPTS
#define DOWNROLL_INTERRUPTS

#include "vbl.h"
#include "ikbd.h"
#include "music.h"
#include "render.h"
#include "types.h"
#include "ikbd.h"
#include "music.h"
#include "render.h"
#include "types.h"


typedef void (*Vector) ();


extern int MUSIC_TIMER;
extern int GAME_TIMER;
extern bool RENDER_REQUEST;
extern bool RENDER_MOUSE_REQUEST;


extern int MOUSE_X;
extern int MOUSE_Y;


extern bool MOUSE_LEFT_CLICK;

extern UINT8 mouse_button;
extern UINT8 mouse_delta_y;
extern UINT8 mouse_delta_x;
extern int prev_mouse_x;
extern int prev_mouse_y;
extern bool mouse_moved;

extern UINT8 ikbdBuffer[IKBDBUFFERSIZE];
extern unsigned int buff_head;
extern unsigned int buff_tail;
extern Vector vbl_vector;
extern Vector ikbd_vector;


/*
Used for timing.
*/
void do_vbl_isr();

/*
Processes input from keyboard and mouse.
*/
void do_ikbd_isr();

/*
Initializes mouse.
*/
void initializeMouse(UINT16* base);

/*
Updates the mouse location.
*/
void updateMouse(UINT16* base);

/*
Installs Vectors.
*/
Vector install_vector(int num, Vector vector);

/*
Installs Vectors.
*/
void install_vectors();

/*
Removes Vectors
*/
void remove_vectors();

/*
Check to see if the keyboard is ready for input.
*/
bool ikbdWaiting();

/*
Check to see if the mouse has moved.
*/
bool ikbdMouseMoved();

/*
Writes to the buffer.
*/
void writeToBuffer(UINT8 scancode);

/*
Reads from the buffer.
*/
unsigned long readFromBuffer();

/*
Clears the buffer.
*/
void clearBuffer();

#endif
