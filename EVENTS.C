/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose: Handles Events such
1) Collision with the ball and the platform
2) If the ball is within the gap of the platform
3) Collision with the ball and the border

*/
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
#include "events.h"
#include "effects.h"

void collision(struct Ball *ball, struct Platform platforms [], struct ScoreBox *scorebox)
{
	if(ball->bottomRightCornerY >= 1 && ball->bottomRightCornerY <= platforms[0].yCord)
	{
		withinGap(ball,platforms[0],scorebox);
	}
	else if(ball->bottomRightCornerY > (platforms[0].yCord) && ball->bottomRightCornerY <= platforms[1].yCord)
	{
		withinGap(ball,platforms[1],scorebox);
	}
	else if(ball->bottomRightCornerY > (platforms[1].yCord) && ball->bottomRightCornerY <= platforms[2].yCord)
	{
		withinGap(ball,platforms[2],scorebox);
	}
	else if(ball->bottomRightCornerY > (platforms[2].yCord) && ball->bottomRightCornerY <= platforms[3].yCord)
	{
		withinGap(ball,platforms[3],scorebox);
	}
	else if(ball->bottomRightCornerY > (platforms[3].yCord) && ball->bottomRightCornerY <= platforms[4].yCord)
	{
		withinGap(ball,platforms[4],scorebox);
	}
	else if(ball->bottomRightCornerY > (platforms[4].yCord) && ball->bottomRightCornerY <= platforms[5].yCord)
	{
		withinGap(ball,platforms[5],scorebox);
	}
	else
	{
		
	}
}
void withinGap(struct Ball *ball, struct Platform pf,struct ScoreBox *scorebox)
{
	if(ball->x > pf.startGap && ball->bottomRightCornerX < pf.endGap)
	{
		ball->hit = 0;
		ball->vDirection = 1;
		scorebox->score = scorebox->score + 1;
		play_1up_effect();
		
	}
	else
	{
		platformCollision(ball, pf);
	}
	
}

void platformCollision(struct Ball *ball, struct Platform pf)
{
	if(ball->bottomRightCornerY <= (pf.yCord+ PLATFORM_HEIGHT))
	{
		
		ball->hit = 1;
		ball->vDirection = - 1;
		ball->bottomRightCornerY = pf.yCord;
		ball->y = ball->bottomRightCornerY - BALL_HEIGHT;
	}
}

void borderCollision(struct Ball *ball)
{
	if(ball->bottomRightCornerX <= BALL_WIDTH)
	{
		ball->x = 0;
		ball->bottomRightCornerX = ball->x + BALL_WIDTH;
	}
	else if(ball->bottomRightCornerX >= endOfBorder)
	{
		ball->bottomRightCornerX = (endOfBorder-1);
		ball->x = ball->bottomRightCornerX - BALL_WIDTH;
	}
	else
	{
		/*Nothing*/
	}
}