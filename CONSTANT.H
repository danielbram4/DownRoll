/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose: Contains constants used throughout the game.
*/
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "types.h"

/* CONSTANTS FOR DOWNROLL.C */

#define SCREEN_SIZE 32256
#define BALL_MAX_Y 16
#define BALL_MIN_Y 390
#define SCORE_TO_WIN 150
#define BALL_STARTING_X 344
#define BALL_STARTING_Y 125
#define BALL_DELTA_X 25
#define BALL_HEIGHT 16
#define BALL_WIDTH 16

/*CONSTANTS FOR EVENTS.C*/
#define PLATFORM_HEIGHT 1

/*CONSTANTS FOR ISR.C*/

#define ASCII_ADDRESS 0xFFFE829C
#define IKBD_ADDRESS 0xFFFC00
#define IKBD_RDR_ADDRESS 0xFFFC02
#define MFP_ADDRESS 0xFFFA11

#define MOUSE_START_X 360
#define MOUSE_START_Y 200

#define VBL_ISR 28
#define IKBD_ISR 70

#define MFB_BIT_6_MASK_ON 0x40
#define MFB_BIT_6_MASK_OFF 0xBF

#define MOUSE_STATE_FIRST_PACKET 0
#define MOUSE_STATE_DELTA_X 1
#define MOUSE_STATE_DELTA_Y 2

#define MOUSE_MOVE_CODE 0xF8
#define MOUSE_LEFT_BUTTON_CODE 0xFA

#define IKBDBUFFERSIZE 256

#define BREAK_CODE_MASK 0x80
#define STATUS_MASK 0x1

/*CONSTANTS FOR MENU.C*/

#define INVALID_MOUSEOPTION -1

#define SELECTION_X 190
#define SELECTION_1PLAYERY 180
#define SELECTION_2PLAYERY 220
#define SELECTION_QUIT_Y 260

#define ESC_KEY 0x0001001B
#define LEFT_KEY 0x004B0000
#define RIGHT_KEY 0x004D0000
#define UP_KEY 0x00480000
#define DOWN_KEY 0x00500000
#define ENTER_KEY 0x001C000D

/*CONSTANTS FOR MUSIC.H*/
#define NOTE_C 0x0D6
#define NOTE_C_SHARP 0x0CA
#define NOTE_D 0x0BE 
#define NOTE_D_SHARP 0x0B4
#define NOTE_E  0x0AA
#define NOTE_F 0x0A0
#define NOTE_F_SHARP 0x097
#define NOTE_G 0x087
#define NOTE_G_SHARP 0x10D
#define NOTE_A 0x0FE
#define NOTE_A_SHARP 0x0F0
#define NOTE_B 0x0E2

#define NOTES_SZ 32

#define INIT_A 0xDC


/*CONSTANTS FOR PSG.C*/

#define CH_A_TONE 0x0
#define CH_B_TONE 0x2
#define CH_C_TONE 0x4

#define CH_A_ROUGH_TONE 0x1
#define CH_B_ROUGH_TONE 0x3
#define CH_C_ROUGH_TONE 0x5

#define CH_A_VOL 0x08
#define CH_B_VOL 0x09
#define CH_C_VOL 0x0A
#define FULL_VOL 0x0F

#define MIXER_ALL_OFF 0xff
#define MIXER_TONE_CH_A 0x3e
#define MIXER_TONE_CH_B 0x3d
#define MIXER_TONE_CH_C 0x3b
#define MIXER_NOISE_CH_A 0x37
#define MIXER_NOISE_CH_B 0x2f
#define MIXER_NOISE_CH_C 0x1f

#define NOISE_FREQUENCY_REG 0x06
#define MIXER_REG 0x07

#define ENVELOPE_FINE_REG 0xb
#define ENVELOPE_ROUGH_REG 0xc
#define ENVELOPE_SHAPE_CONTROL_REG 0xd

#define ENV_SHAPE_1 0x8 /* Envelope shapes based on the order of shapes in the YM2149 application manual */
#define ENV_SHAPE_2 0x9
#define ENV_SHAPE_3  0xA
#define ENV_SHAPE_4 0xB
#define ENV_SHAPE_5 0xC
#define ENV_SHAPE_6  0xD
#define ENV_SHAPE_7 0x0E
#define ENV_SHAPE_8 0x07

#define reg_is_valid(reg) (reg >= 0 && reg <= 15)

#define REGISTER_SELECT_ADDRESS 0xFF8800
#define REGISTER_WRITE_ADDRESS 0xFF8802

/*CONSTANTS FOR RASTER.C*/

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define SOLID         0xFFFF
#define BITS_IN_BYTE  16
#define TWO_CUBED	  4
#define platformHeight 1

/*CONSTANTS FOR MODEL.C*/

#define gapLength 48
#define gap1_start 80
#define gap2_start 160
#define gap3_start 240
#define gap4_start 320
#define gap5_start 400
#define gap6_start 480

#define lowerPf 1
#define upperPf 6
#define defaultYcordPf 1
#define defaultXcordPf 0
#define defaultDeltaYPf 2 
#define whiteSpacePf 66

#define startOfBorder 0
#define endOfBorder 639

#endif
