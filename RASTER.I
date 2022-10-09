# 1 "raster.c" 1
# 1 "C:/c68/include/stdio.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 11 "C:/c68/include/stdio.h" 2
# 20 "C:/c68/include/stdio.h"
typedef unsigned long  size_t;
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 9 "raster.c" 2
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 10 "raster.c" 2
# 1 "./raster.h" 1
# 1 "./types.h" 1



typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;


typedef enum {
    ch_a, ch_b, ch_c
} channel_t;

typedef enum {
    saw, saw_inv, saw_period, saw_inv_period,
    triangle, triangle_inv, triangle_period, triangle_inv_period
} env_shape_t;

typedef int bool;
# 7 "./raster.h" 2
# 1 "./constant.h" 1
# 1 "./types.h" 1
# 9 "./constant.h" 2
# 8 "./raster.h" 2


void clearScreen(UINT16 *base);
void verticalLine(UINT16 *base, int x, int fromY, int toY);

void plot_bitmap_16(UINT16 *base, int x, int y, UINT16 *bitmap, int height);
void plot_bitmap_menu(UINT16 *base, int x, int y, UINT16 *bitmap, int height);
void plot_bitmap_32(UINT16 *base, int x, int y, UINT32 *bitmap, int height);
void plot_Borders(UINT16 *base, int x, int y, UINT16 *bitmap, int height);




void horizontalGap(UINT16 *base, int fromX, int toX, int y);




void plot_hline (UINT16 *base, int y, int x1, int x2);



void plot_vline (UINT16 *base, int x, int y1, int y2);




void plot_pixel(UINT16 *base, int x, int y);

void plot_screen(UINT32* base, UINT32 * bitmap);




void clearRegion(void *base, int x, int y, int width, int height);
void clearRegion_8(UINT8 *base, int x, int y, int width, int height);
void clearRegion_16(UINT16 *base, int x, int y, int width, int height);
void clearRegion_32(UINT32 *base, int x, int y, int width, int height);

void clear_hline(void *base, int x, int y, int width);
void clear_hline_8(UINT8 *base, int x, int y, int width);
void clear_hline_16(UINT16 *base, int x, int y, int width);
void clear_hline_32(UINT32 *base, int x, int y, int width);
# 11 "raster.c" 2



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
	if (x >= 0 && x < 640  && y >= 0 && y < 400 )
		*(base + y * 40 + (x >> 4)) |= (0x80 >> (x & 15));
}
void clearScreen(UINT16 *base)
{
	int x;
	int y;
	int height = 16;

	for(y = 0; y < 400 ; y+=16)
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


	row1 = x1 >> 4 ;

	row2 = x2 >> 4 ;

	shift_F = x1 & (16  - 1);

	shift_B = (16  - 1) - (x2 & (16 -1));

	if (row1 == row2)
	{
		p1 = 0xFFFF  >> shift_F;
		p2 = 0xFFFF  << shift_B;
		*(base + y * 40 + row1) = p1 & p2;
	}
    else
    {
		p1 = 0xFFFF  >> shift_F;
		p2 = 0xFFFF  << shift_B;
		*(base + y * 40 + row1) = p1;
		for (i = row1 + 1; i < row2; i++)
		{
			*(base + y * 40 + i) = 0xFFFF ;
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

  if(x >= 0 && x < 640  && y >= 0 && y < 400 )
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

  if(x >= 0 && x < 640  && y >= 0 && y < 400 )
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

  if(x >= 0 && x < 640  && y >= 0 && y < 400 )
  {
		offset = ((40 * y) + (x >> 4));

		for (i = 0; i < height; i++)
		{
			offset = (40 * y) + (x >> 4);
			*(base + offset + (40 * i)) =  bitmap[i];
		}
  }
}
