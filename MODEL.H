/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose: Contains game models needed for the game.
*/
#ifndef MODEL_GUARDS
#define MODEL_GUARDS

#include "constants.h"

struct Ball
{ 
    unsigned int x; /*x cords*/
	unsigned int y; /*y cord*/
	int deltaX; /*horiz displacement per arrow press*/
	int deltaY;
	int hit; /* Boolean, 0 = not hit, 1 = hit*/
	int height;
	int width;
	int bottomRightCornerX; /*x + height of ball*/
	int bottomRightCornerY;
	int hDirection; /* Left/Right/Non : -1/1/0*/
	int vDirection; /* Up/Down/Non: -1/1/0*/
};

struct Platform
{
	int platformType;
	int startGap, endGap;
	int xCord;
	int yCord;
	int deltaY; /*vertical displacement per clock tick */
};

struct ScoreBox
{
	int score;
	int xCord, yCord;
	int maxScore; /*Boolean , 0 = if not 99, 1 if 99*/
};

struct Screen
{
	int xCord, yCord;
	int startBorder, endBorder;
	int losingMessage;
	int winningMessage;
	int exitMessage;
	struct ScoreBox scorebox;
	struct Ball ball;
	struct Platform platforms[6];
};

struct Model
{
	struct ScoreBox scorebox;
	struct Ball ball;
	struct Platform platforms[6];
	struct Screen screen;
};
/*
If the ball has collided with a platform(hit is 1), it allows the ball to move left or right, depending
on keyboard input. If the ball has collided with a platform it will also move up with the platforms. 
If the ball has not collided with a platform, it cannot move left or right and instead moves down the screen. 
*/
void move_ball(struct Ball *ball);
/*
Checks if the top platform has hit the top of the screen. If so, the top platform is removed, a new platform 
is generated at the bottom of the screen, and every platform is shifted up 1 in the array.
*/
void checkPlatformStatus(struct Platform platforms[]);
/*
Generates Platforms.
*/
struct Platform generate_platform();
/*
Moves Platforms up on the screen.
*/
void movePlatforms(struct Platform platforms[]);

#endif
