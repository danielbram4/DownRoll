/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose: Draws a single frame of the start of the game,
master render function calls functions to accomplish this.
*/
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
#include "render.h"
#include "splash.h"

UINT16 mouseBackGround[16];

UINT16 mouse_pointer[16] = {
  0x000f,
  0x001f,
  0x003f,
  0x007f,
  0x00ff,
  0x01ff,
  0x03ff,
  0x07ff,
  0x0fff,
  0x1fff,
  0x3fff,
  0x7fff,
  0xffff,
  0xffff,
  0xffff,
  0xffff
};

UINT16 zero_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 one_bitmap[16] =
{
	0xFFC0,
	0xFFC0,
	0xFFC0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0x01C0,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 two_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE000,
	0xE000,
	0xE000,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 three_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 four_bitmap[16] =
{
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007
};

UINT16 five_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE000,
	0xE000,
	0xE000,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 six_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE000,
	0xE000,
	0xE000,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 seven_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007
};

UINT16 eight_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xFFFF,
	0xFFFF,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xFFFF,
	0xFFFF,
	0xFFFF
};

UINT16 nine_bitmap[16] =
{
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xE007,
	0xE007,
	0xE007,
	0xE007,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007
};

UINT16 ball_bitmap[16] = 
	{
		0x07E0,
		0x1FF8,
		0x3FFC,
		0x7FFE,
		0x7FFE,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0x7FFE,
		0x7FFE,
		0x3FFC,
		0x1FF8,
		0x07E0
	};


void render(const struct Model *model, UINT16 *base)
{
	clear_qk(base);
	render_ScoreBox(&(model->scorebox), base);
	render_Platforms(&(model->platforms), base);
	render_Ball(&(model->ball), base);
}

void render_Ball(const struct Ball *ball, UINT16 *base)
{
	plot_bitmap_16(base,ball->x,ball->y,ball_bitmap,ball->height);
}
void render_splashScreen(UINT32 *base)
{
	clear_qk(base);
	plot_screen(base,splash);
}
void render_ScoreBox(const struct ScoreBox *scorebox, UINT16 *base)
{
	int gameScore = 0;
	int lsi = 0;
	int msi = 0;
	int middle = 0;
	gameScore = scorebox->score;
	msi = gameScore / 100; /*Most sigificant int*/
	middle = (gameScore / 10) % 10; /*Middle int*/
	lsi = gameScore % 10; /*Least sigificant int*/
	switch(msi)
	{
		case 0: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,zero_bitmap,16);
			break;
		case 1: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,one_bitmap,16);
			break;
		case 2: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,two_bitmap,16);
			break;
		case 3: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,three_bitmap,16);
			break;
		case 4: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,four_bitmap,16);
			break;
		case 5: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,five_bitmap,16);
			break;
		case 6: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,six_bitmap,16);
			break;		
		case 7: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,seven_bitmap,16);
			break;
		case 8: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,eight_bitmap,16);
			break;
		case 9: plot_bitmap_16(base,scorebox->xCord,scorebox->yCord,nine_bitmap,16);
			break;
	}
	switch(middle)
	{
		case 0: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,zero_bitmap,16);
			break;
		case 1: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,one_bitmap,16);
			break;
		case 2: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,two_bitmap,16);
			break;
		case 3: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,three_bitmap,16);
			break;
		case 4: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,four_bitmap,16);
			break;
		case 5: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,five_bitmap,16);
			break;
		case 6: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,six_bitmap,16);
			break;		
		case 7: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,seven_bitmap,16);
			break;
		case 8: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,eight_bitmap,16);
			break;
		case 9: plot_bitmap_16(base,scorebox->xCord + 17,scorebox->yCord,nine_bitmap,16);
			break;
	}
	switch(lsi)
	{
		case 0: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,zero_bitmap,16);
			break;
		case 1: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,one_bitmap,16);
			break;
		case 2: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,two_bitmap,16);
			break;
		case 3: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,three_bitmap,16);
			break;
		case 4: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,four_bitmap,16);
			break;
		case 5: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,five_bitmap,16);
			break;
		case 6: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,six_bitmap,16);
			break;		
		case 7: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,seven_bitmap,16);
			break;
		case 8: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,eight_bitmap,16);
			break;
		case 9: plot_bitmap_16(base,scorebox->xCord + 34,scorebox->yCord,nine_bitmap,16);
			break;
	}
	
	
	
}
void render_Platforms(struct Platform platforms[], UINT16 *base)
{
	
	int i;
	int numberOfPlatforms = 6;
	int bottomOfScreen = 400;
	
	for (i = 0; i < 6; i++)
	{
		if(platforms[i].yCord <= bottomOfScreen)
		{
			render_platform(platforms[i], base);
		}
	}
}

void render_platformBlock(struct Platform pf, UINT16 *base)
{
	int i;
	int yCord;
	
	yCord = pf.yCord;
	/*horitzonalLine(base, 214, 430, yCord);*/
	/*plot_hline (base, yCord, 214, 430);*/
	plot_hline (base, yCord, 0, 640);
	
}

void render_platform(struct Platform pf, UINT16 *base)
{
	int i;
	int yCord;
	
	render_platformBlock(pf, base);

	yCord = pf.yCord;
	
	horizontalGap(base, pf.startGap, pf.endGap, yCord);
	
}
void saveMouseBackGround(UINT16 *base, int x, int y) 
{
	int i;
	int j;

	for(i = 0, j = 0; i < 16; i++)
	{
		mouseBackGround[j++] = *(base + (y + i) * 40 + (x >> 4));
	}
}

void restoreMouseBackGround(UINT16 *base, int x, int y) 
{
	int i;
	int j;

	for(i = 0, j = 0; i < 16; i++)
	{
		*(base + (y + i) * 40 + (x >> 4)) = mouseBackGround[j++];
	}
}

void renderMousePointer(UINT16 *base, int x, int y) 
{
	plot_bitmap_menu(base, x, y, mouse_pointer, 16);
}

void disable_cursor() 
{
	printf("\033f");
	fflush(stdout);
}

