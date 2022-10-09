#ifndef TYPES_H
#define TYPES_H

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
#define true 1
#define false 0
#endif
