/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef EVENTS_GUARDS
#define EVENTS_GUARDS
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
#include "model.h"
#include "constants.h"

/*
Checks where the ball is in the screen(in between which platforms), then checks if the ball is within the gap
of the platform it collided with.
*/
void collision(struct Ball *ball, struct Platform platforms [], struct ScoreBox *scorebox);
/*
checks if the ball is within the gap of the platform it collided with. If the ball is within the gap,
it will allow the ball to go down the gap(ie down the screen).Otherwise it checks if collision has occured
with a platform.
*/
void withinGap(struct Ball *ball, struct Platform pf,struct ScoreBox *scorebox);
/*
Checks if ball has collided with the left or right border of the screen.
*/
void borderCollision(struct Ball *ball);
/*
Checks if ball has collided with a platform. If so, the ball will move up with the platform. 
*/
void platformCollision(struct Ball *ball, struct Platform pf);


#endif
