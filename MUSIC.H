/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef DOWNROLL_MUSIC_H
#define DOWNROLL_MUSIC_H

#include "psg.h"
#include "types.h"
#include "constant.h"

typedef struct {
    int freq;
    int duration;
} note_t;

/*
 * Starts music.
 */
void start_music();

/*
Updates Music.
*/
bool update_music(UINT32 time_elapsed);

#endif 