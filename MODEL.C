/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose: Enacts actions that the ball and the platform will perform
For the ball, we have a move function
For the platforms, we have generation, shifting, and movement.

*/
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
#include "model.h"
#include "events.h"
#include "input.h"
#include "constants.h"

void move_ball(struct Ball *ball)
{	
	if(ball->hit == 1)
	{
		ball->x = ball->x + (ball->deltaX * ball->hDirection);
		ball->bottomRightCornerX = ball->bottomRightCornerX + (ball->deltaX * ball->hDirection);
		ball->y = ball->y + (ball->deltaY * ball->vDirection);
		/*Added this line below*/
		ball->bottomRightCornerY = ball->bottomRightCornerY + (ball->deltaY * ball->vDirection);
		borderCollision(ball); /*Check if border collision occurs*/
	}
	else
	{
		ball->y = ball->y + (ball->deltaY * ball->vDirection);
		/*Added this line below*/
		ball->bottomRightCornerY = ball->bottomRightCornerY + (ball->deltaY * ball->vDirection);
	}

}

void checkPlatformStatus(struct Platform platforms[])
{
	struct Platform temp;
	if(platforms[0].yCord <= 0)
	{
		temp = platforms[1];
		platforms[1] = platforms[2];
		platforms[2] = platforms[3];
		platforms[3] = platforms[4];
		platforms[4] = platforms[5];
		platforms[5] = generate_platform(lowerPf, upperPf, defaultXcordPf, 397,defaultDeltaYPf);
		while(platforms[5].platformType == platforms[4].platformType)
		{
			platforms[5] = generate_platform(lowerPf, upperPf, defaultXcordPf, 397,defaultDeltaYPf);
		}
		platforms[0] = temp;
	}
}
void movePlatforms(struct Platform platforms[])
{
	int i;
	for(i = 0; i < 6; i++) 
	{
		platforms[i].yCord = platforms[i].yCord - defaultDeltaYPf;	
	}
	checkPlatformStatus(platforms);
}
struct Platform generate_platform(int lower, int upper, int defaultXcord, int defaultY, int defaultDeltaY)
{
	struct Platform *newPlatform;
	newPlatform->platformType = ((((rand() % (upper - lower + 1)) + lower) + rand()) % (upper - lower + 1));
	newPlatform->xCord = defaultXcord;
	newPlatform->yCord = defaultY;
	newPlatform->deltaY = defaultDeltaY;
	
	switch(newPlatform->platformType)
	{
		case 1: newPlatform->startGap = gap1_start;
				newPlatform->endGap = gap1_start + gapLength;
			break;
		case 2: newPlatform->startGap = gap2_start;
				newPlatform->endGap = gap2_start + gapLength;
			break;
		case 3: newPlatform->startGap = gap3_start;
				newPlatform->endGap = gap3_start + gapLength;
			break;
		case 4: newPlatform->startGap = gap4_start;
				newPlatform->endGap = gap4_start + gapLength;
			break;
		case 5: newPlatform->startGap = gap5_start;
				newPlatform->endGap = gap5_start + gapLength;
			break;
		case 6: newPlatform->startGap = gap6_start;
				newPlatform->endGap = gap6_start + gapLength;
			break;
		
	}
	
	return *newPlatform;
}