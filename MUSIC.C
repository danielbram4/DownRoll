/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#include "music.h"

static int current_note = 0;

const note_t main_song[] = {

  {NOTE_C, 10},
  {0,   2},
  {NOTE_C, 10},
  {0,   2}, 
  {NOTE_C, 10},
  {0,   2},
  {NOTE_C, 10},
  {0,   2},
  
  {NOTE_C_SHARP, 10},
  {0,   2},
  {NOTE_C_SHARP, 10},
  {0,   2}, 
  {NOTE_C_SHARP, 10},
  {0,   2},
  {NOTE_C_SHARP, 10},
  {0,   2},
  
  {NOTE_E, 10},
  {0,   2},
  {NOTE_E, 10},
  {0,   2}, 
  {NOTE_E, 10},
  {0,   2},
  {NOTE_E, 10},
  {0,   2},
  
  {NOTE_D_SHARP, 10},
  {0,   2},
  {NOTE_D_SHARP, 10},
  {0,   2}, 
  {NOTE_D_SHARP, 10},
  {0,   2},
  {NOTE_D_SHARP, 10},
  {0,   2},

};

/*Enable channels and set initial vol to channel A*/
void start_music() {
  write_psg(MIXER_REG, INIT_A);
  write_psg(CH_A_VOL, FULL_VOL);
}

bool update_music(UINT32 time_elapsed) {
  bool updated = false;

  if (time_elapsed >= main_song[current_note].duration) {
    current_note++;
	updated = true;
  }

  if (current_note > (NOTES_SZ - 1))
    current_note = 0;

  set_tone(ch_a, main_song[current_note].freq);

  return updated;
}
