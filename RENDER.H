/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef RENDER_GUARDS
#define RENDER_GUARDS
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>

#include "model.h"
#include "types.h"
#include "raster.h"
#include "constants.h"
#include "clear.h"


/*
Renders the entire game, aka models and the screen.
*/
void render(const struct Model *model, UINT16 *base);
/*
Renders the ball.
*/
void render_Ball(const struct Ball *ball, UINT16 *base);
/*
Renders a single platform.
*/
void render_platform(struct Platform pf, UINT16 *base);
/*
Renders platform width.
*/
void render_platformBlock(struct Platform pf, UINT16 *base);
/*
Renders 6 platforms.
*/
void render_Platforms(struct Platform platforms[], UINT16 *base);
/*
Renders the scorebox.
*/
void render_ScoreBox(const struct ScoreBox *scorebox, UINT16 *base);

/*
Renders the splash Screen.
*/
void render_splashScreen(UINT32 *base);

/*
Used for mouse rendering.
*/
void saveMouseBackGround(UINT16 *base, int x, int y);
void restoreMouseBackGround(UINT16 *base, int x, int y);
void renderMousePointer(UINT16 *base, int x, int y);

void disable_cursor();
#endif
