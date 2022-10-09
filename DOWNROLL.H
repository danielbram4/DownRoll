/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef DOWNROLL_GUARDS
#define DOWNROLL_GUARDS
#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "render.h"
#include "raster.h"
#include "events.h"
#include "types.h"
#include "constants.h"
#include "video.h"

/*Game Loop*/
void game_loop();
/*
Obtains 256 byte alligned address needed for frame buffer.
*/
UINT8* getFBAddress();
/*
Sets up the game, creates models used in game and initalizes them to appropriate values. 
*/
void setUpGame(struct Model *model);
/*
Checks if the ball collides with the bottom of the screen, if so prevents ball from going below the screen.
*/
void checkBallBottomCollision(struct Ball *ball);

/*
Processes asynchronous events such as the ball movement.
*/
void processAsyncEvents(struct Ball *ball);
/*
Processes synchronous events such as platform movement and collisions.
*/
void processSyncEvents(struct Model *model);

#endif
