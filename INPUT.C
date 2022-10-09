/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#include <stdio.h>
#include <osbind.h>
#include "input.h"
#include "isr.h"
#include "ikbd.h"

unsigned long readInput()
{
	unsigned long input = 0;
	if(ikbdWaiting())
	{
		input = readFromBuffer();
	}
	return input;
}

