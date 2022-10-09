/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil

Purpose:
File Contains functions, all of which interact with the frame buffer.

*/
#include <stdio.h>
#include <osbind.h>
#include "raster.h"


UINT16 whiteBlock16[16] = 
	{
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x0000
	};
	
UINT16 blackBlock[16] = 
	{
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF
	
	};

void plot_pixel(UINT16 *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		*(base + y * 40 + (x >> 4)) |= (0x80 >> (x & 15));
}
void clearScreen(UINT16 *base)
{
	int x;
	int y;
	int height = 16;

	for(y = 0; y < SCREEN_HEIGHT; y+=16)
	{
		for(x = 208; x < 416; x+=16)
		{
			plot_bitmap_16(base,x ,y, whiteBlock16, height);
		}
	}
}
void plot_screen(UINT32* base, UINT32 * bitmap)
{
	int i;
	for(i = 0;i < 8000 ;i++)
	{
		*(base + i) = bitmap[i];
	}
}
void verticalLine(UINT16 *base, int x, int fromY, int toY)
{
	int height = toY - fromY; 
	int offset = 0;
	int i = 0;
	int xCord = x;
	int yCord = fromY;
	for(i = 0; i < height; i++)
	{
			offset = (40 * yCord) + (xCord >> 4);
			*(base + offset + (40 * i)) =  0x0200 >> (xCord & 15);
			*(base + offset + (40 * i) + 1) =  0x0F00 << 16 - (xCord & 15);
	}
}

void plot_hline (UINT16 *base, int y, int x1, int x2)
{
	UINT16 p1, p2;
	int row1, row2, i;
	int shift_F, shift_B;

/*	row1 = x1 / BITS_IN_BYTE; */
	row1 = x1 >> TWO_CUBED;
/*	row2 = x2 / BITS_IN_BYTE; */
	row2 = x2 >> TWO_CUBED;
/*	shift_F = x1 % BITS_IN_BYTE; */
	shift_F = x1 & (BITS_IN_BYTE - 1);
/*	shift_B = (BITS_IN_BYTE - 1) - (x2 % BITS_IN_BYTE); */
	shift_B = (BITS_IN_BYTE - 1) - (x2 & (BITS_IN_BYTE-1));

	if (row1 == row2)
	{
		p1 = SOLID >> shift_F;
		p2 = SOLID << shift_B;
		*(base + y * 40 + row1) = p1 & p2;
	}
    else
    {
		p1 = SOLID >> shift_F;
		p2 = SOLID << shift_B;
		*(base + y * 40 + row1) = p1;
		for (i = row1 + 1; i < row2; i++)
		{
			*(base + y * 40 + i) = SOLID;
		}
		*(base + y * 40 + row2) = p2;
  }
  return;
}

void plot_vline (UINT16 *base, int x, int y1, int y2)
{
  int temp;
  
  if (y1 > y2)	
  {
	  temp = y1;
	  y1 = y2;
	  y2 = temp;
  }
  if (y1 < 0) y1 = 0;
  if (y2 > 399) y2 = 399;
  
  for ( ; y1 <= y2; y1++)
	  plot_pixel(base, x, y1);
  
  return;
}


void horizontalGap(UINT16 *base, int fromX, int toX, int y)
{
	int offset = 0;
	int i = 0;
	int xCord = fromX;
	int yCord = y;
	for(xCord = fromX; xCord < toX; xCord++)
	{
		offset = (40 * yCord) + (xCord >> 4);
		*(base + offset + (40 * i)) =  0x00000000;
	}
}


void clearRegion(void *base, int x, int y, int width, int height) 
{
	if (width <= 8)
	{
		clearRegion_8(base, x, y, width, height);
	}
	else if (width <= 16)
	{
		clearRegion_16(base, x, y, width, height);
	}
	else
	{
		clearRegion_32(base, x, y, width, height);
	}

}

void clearRegion_8(UINT8 *base, int x, int y, int width, int height) 
{
	int i;
	int j;
	UINT8 *draw = base;
	for (i = 0; i < height; i++) 
	{
		clear_hline(draw, x, y, width);
		draw += 80;
	}
}

void clearRegion_16(UINT16 *base, int x, int y, int width, int height) 
{
	int i;
	int j;
	UINT16 *draw = base;
	for (i = 0; i < height; i++) 
	{
		clear_hline(draw, x, y, width);
		draw += 40;
	}
}

void clearRegion_32(UINT32 *base, int x, int y, int width, int height) 
{
	int i;
	int j;
	UINT32 *draw = base;
	for (i = 0; i < height; i++) 
	{
		clear_hline(draw, x, y, width);
		draw += 20;
	}
}

void clear_hline(void *base, int x, int y, int width) 
{
	if (width <= 8)
	{
		clear_hline_8(base, x, y, width);
	}
	else if (width <= 16)
	{
		clear_hline_16(base, x, y, width);
	}
	else
	{
		clear_hline_32(base, x, y, width);
	}
}

void clear_hline_8(UINT8 *base, int x, int y, int width) 
{
	int i = 0;
	int x_count = width >> 3;
	UINT8 *draw = base + (y * 80) + (x >> 3);

	for (i = 0; i < x_count; i++)
		*(draw++) = 0xff;
}

void clear_hline_16(UINT16 *base, int x, int y, int width) 
{
	int i = 0;
	int x_count = width >> 4;
	UINT16 *draw = base + (y * 40) + (x >> 4);

	for (i = 0; i < x_count; i++)
	{
		*(draw++) = 0xffff;
	}
}

void clear_hline_32(UINT32 *base, int x, int y, int width) 
{
	int i = 0;
	int x_count = width >> 5;
	UINT32 *draw = base + (y * 20) + (x >> 5);

	for (i = 0; i < x_count; i++)
	{
		*(draw++) = 0xffffffff;
	}
}

void plot_bitmap_16(UINT16 *base, int x, int y, UINT16 *bitmap, int height)
{
  int offset;
  int i;
  
  if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
  {
		offset = ((40 * y) + (x >> 4));

		for (i = 0; i < height; i++)
		{
			*(base + offset + (40 * i)) = bitmap[i] >> (x & 15);
			*(base + offset + (40 * i) + 1) = bitmap[i] << 16 - (x & 15);
		}
  }
}

void plot_bitmap_menu(UINT16 *base, int x, int y, UINT16 *bitmap, int height) 
{
	int i = 0;
	UINT16 *location = base + (y * 40) + (x >> 4);
	for (i = 0; i < height; i++) 
	{
		*location &= *(bitmap++);
		location += 40;
	}
}



void plot_bitmap_32(UINT16 *base, int x, int y, UINT32 *bitmap, int height)
{
  int offset;
  int i;
  
  if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
  {
		offset = ((20 * y) + (x >> 5));

		for (i = 0; i < height; i++)
		{
			*(base + offset + (20 * i)) = bitmap[i] >> (x & 31);
			*(base + offset + (20 * i) + 1) = bitmap[i] << 32 - (x & 31);
		}
  }
}
void plot_Borders(UINT16 *base, int x, int y, UINT16 *bitmap, int height)
{
	int offset;
	int i;
	int bShift;
  
  if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
  {
		offset = ((40 * y) + (x >> 4));

		for (i = 0; i < height; i++)
		{
			offset = (40 * y) + (x >> 4);
			*(base + offset + (40 * i)) =  bitmap[i];
		}
  }
}



