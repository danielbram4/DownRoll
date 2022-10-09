/**
 *  Authors: Scott Charles, Daniel Bahrami
 */
/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef DOWNROLL_PSG_H
#define DOWNROLL_PSG_H

#include <osbind.h>
#include "types.h"
#include "constant.h"



extern volatile char* psg_reg_select = REGISTER_SELECT_ADDRESS;
extern volatile char* psg_reg_write  = REGISTER_WRITE_ADDRESS;


void write_psg(int reg, UINT8 val);


int read_psg(int reg);


void set_tone(channel_t channel, int tuning);


void set_noise(int tuning);


void set_envelope_shape(int shape);


void set_envelop(UINT16 sustain);


void set_volume(channel_t channel, int vol);


void enable_channel(channel_t channel, bool tone_on, bool noise_on);
void enable_channel_(int channel, bool tone_on, bool noise_on);

void stop_sound();

#endif 