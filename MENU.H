/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef MENU_H
#define MENU_H

#include <osbind.h>
#include <stdio.h>

#include "constant.h"
#include "events.h"
#include "downroll.h"
#include "raster.h"
#include "render.h"
#include "types.h"
#include "isr.h"

extern int MENU_STATE;

extern bool CLICK_IS_VALID;

/*
Processes menu.
*/
void menu();

/*
Selects menu option chosen.
*/
void selectOption(int option);

/*
Draws the keyboard menu arrow.
*/
void drawKeyboardArrow(int option, UINT16* base);

/*
Clears the keyboard menu arrow.
*/
void clearKeyboardArrow(int option, UINT16* base);

/*
Gives the location of the mouse.
*/
int mouseLocation();

#endif
