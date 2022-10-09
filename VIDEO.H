/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef VIDEO_H
#define VIDEO_H

#include "types.h"

/*
Replaces Physbase
*/
UINT16 *get_video_base();

/*
Replaces Set Screen, sets the screen to the given base
*/
void set_video_base(UINT16* FB);

#endif