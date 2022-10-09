/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose: Main Game Module.

-------IMPORTANT: At this stage, the left and right keys are used for movement.---------

*/
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "downroll.h"
#include "constants.h"
#include "psg.h"
#include "music.h"
#include "effects.h"
#include "isr.h"
#include "ikbd.h"
#include "input.h"
#include "menu.h"
#include "splash.h"




const UINT8 arrayScreen[SCREEN_SIZE];

int main()
{
	
	UINT16 *FB = get_video_base();
	
	install_vectors();
	
	disable_cursor();
	
	render_splashScreen((UINT32 *)FB);
	menu();
	stop_sound();
	
	play_explosion_effect();
	
	clearBuffer();
    remove_vectors();
	return 0;
}

void game_loop()
{
	UINT16 *FB = get_video_base();
	UINT16 *FB2 = (UINT16 *) getFBAddress();
	bool swap_screens = false;
	struct Model model;
	
	setUpGame(&model);
	start_music();
	
	/*main game loop*/
	while(model.ball.bottomRightCornerY > BALL_MAX_Y && model.scorebox.score <= SCORE_TO_WIN) 
	{
		if(update_music(MUSIC_TIMER))
		{
			MUSIC_TIMER = 0;
		}
		
		if (RENDER_REQUEST) 
		{
			processAsyncEvents(&(model.ball));
			processSyncEvents(&model);
			if (swap_screens) 
			{
				render(&model, FB2);
				
				set_video_base(FB2);
				
			} 
			else 
			{
				render(&model, FB);
				
				set_video_base(FB);
			}	
			RENDER_REQUEST = false;
			swap_screens = !swap_screens;
		}
	}	
	set_video_base(FB);
}
void processAsyncEvents(struct Ball *ball)
{
	unsigned long kbInput;
	
	if(ball->hit == 1)
	{
		kbInput = readInput();
		if(kbInput == LEFT_KEY) /*represents left key*/
		{
			ball->hDirection = -1;
		}
		else if(kbInput == RIGHT_KEY) /*represents right key*/
		{
			ball->hDirection = 1;
		}
		else
		{
			ball->hDirection = 0;
		}
		ball->vDirection = -1;
	}
	else
	{
		ball->vDirection = 1;
	}
}
void processSyncEvents(struct Model *model)
{
	move_ball(&(model->ball));
	checkBallBottomCollision(&(model->ball));
	movePlatforms(&(model->platforms));
	collision(&(model->ball), &(model->platforms), &(model->scorebox));
}
void setUpGame(struct Model *model)
{

	model->platforms[0] = generate_platform(lowerPf, upperPf, defaultXcordPf, defaultYcordPf, defaultDeltaYPf);
	model->platforms[1] = generate_platform(lowerPf, upperPf, defaultXcordPf, defaultYcordPf + (whiteSpacePf), defaultDeltaYPf);
	model->platforms[2] = generate_platform(lowerPf, upperPf, defaultXcordPf, defaultYcordPf + (whiteSpacePf * 2), defaultDeltaYPf);
	model->platforms[3] = generate_platform(lowerPf, upperPf, defaultXcordPf, defaultYcordPf + (whiteSpacePf * 3), defaultDeltaYPf);
	model->platforms[4] = generate_platform(lowerPf, upperPf, defaultXcordPf, defaultYcordPf + (whiteSpacePf * 4), defaultDeltaYPf);
	model->platforms[5] = generate_platform(lowerPf, upperPf, defaultXcordPf, defaultYcordPf + (whiteSpacePf * 5), defaultDeltaYPf);

	model->screen.startBorder = 0;
	model->screen.endBorder = SCREEN_WIDTH - 1; 
	
	model->ball.x = BALL_STARTING_X;
	model->ball.y = BALL_STARTING_Y;
	model->ball.deltaX = BALL_DELTA_X;
	model->ball.deltaY = defaultDeltaYPf; /*Same as platform delta Y*/
	
	model->ball.bottomRightCornerX = model->ball.x + BALL_WIDTH;
	model->ball.bottomRightCornerY = model->ball.y + BALL_HEIGHT;
	
	model->ball.hit = 1;
	model->ball.height = BALL_HEIGHT;
	model->ball.width = BALL_WIDTH;
	
	model->scorebox.score = 0;
	model->scorebox.xCord = 0;
	model->scorebox.yCord = 0;
	model->scorebox.maxScore = 0;
	
}

void checkBallBottomCollision(struct Ball *ball)
{
	if(ball->bottomRightCornerY >= BALL_MIN_Y)
	{
		ball->bottomRightCornerY = BALL_MIN_Y;
		ball->y = ball->bottomRightCornerY - BALL_HEIGHT;
	}
}

UINT8* getFBAddress()
{
	UINT8* base;
	UINT16 difference;
	base = arrayScreen;
	difference = (int) base;
	difference %= 0x100;
	difference = 0x100 - difference;
	return base + difference;
}
