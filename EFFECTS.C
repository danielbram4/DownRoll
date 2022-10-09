
/**
 *  Authors: Scott Charles, Daniel Bahrami
 */
#include "effects.h"

void play_explosion_effect() {
	
  int sustain = 0x0F;
  int enable_C = 0x18;
  int envelope_shape = 2;
  int explosion_tone = 0xAF;
  int vol = 0x1F;
  
   
  enable_channel(ch_c, false, true);
  set_noise(explosion_tone);
  set_volume(ch_c, vol);
  set_envelop(sustain);
  set_envelope_shape(envelope_shape);
  
}

/*
*The recommended psg library methods do not include a
*method that enables 2 channels at one time. This method
*enables A and C.
*/
void play_1up_effect() {
  
  int enable_C_and_A = 0x38;
  int envelope_shape = 2;
  int c_tone = 0x35;
  int c_rough_tone = 0x10;
  int vol = 0x1F;
  int sustain = 0x0F;
  
  /*Enable both channel A & C */
  write_psg(MIXER_REG, enable_C_and_A);
  set_tone(ch_c, c_tone);
  
  /* set the rough tone of channel c */
  write_psg(CH_C_ROUGH_TONE, c_rough_tone);
  set_volume(ch_c, vol);
  set_envelop(sustain);
  set_envelope_shape(envelope_shape);
}
