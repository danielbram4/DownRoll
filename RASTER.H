/*
Authors: Daniel Bahrami, Scott Charles
Instructor: Paul Pospisil
*/
#ifndef RASTER_H
#define RASTER_H
#include "types.h"
#include "constant.h"

void clearScreen(UINT16 *base);
void verticalLine(UINT16 *base, int x, int fromY, int toY);

void plot_bitmap_16(UINT16 *base, int x, int y, UINT16 *bitmap, int height);
void plot_bitmap_menu(UINT16 *base, int x, int y, UINT16 *bitmap, int height);
void plot_bitmap_32(UINT16 *base, int x, int y, UINT32 *bitmap, int height);
void plot_Borders(UINT16 *base, int x, int y, UINT16 *bitmap, int height);

/*
Purpose: Prints the gap for the platforms.
*/
void horizontalGap(UINT16 *base, int fromX, int toX, int y);

/*
Plots Horizontal Line.
*/
void plot_hline (UINT16 *base, int y, int x1, int x2);
/*
Plots Vertical Line.
*/
void plot_vline (UINT16 *base, int x, int y1, int y2);

/*
Plots Pixel.
*/
void plot_pixel(UINT16 *base, int x, int y);

void plot_screen(UINT32* base, UINT32 * bitmap);

/*
Used for clearing keyboard arrow.
*/
void clearRegion(void *base, int x, int y, int width, int height);
void clearRegion_8(UINT8 *base, int x, int y, int width, int height);
void clearRegion_16(UINT16 *base, int x, int y, int width, int height);
void clearRegion_32(UINT32 *base, int x, int y, int width, int height);

void clear_hline(void *base, int x, int y, int width);
void clear_hline_8(UINT8 *base, int x, int y, int width);
void clear_hline_16(UINT16 *base, int x, int y, int width);
void clear_hline_32(UINT32 *base, int x, int y, int width);


#endif
