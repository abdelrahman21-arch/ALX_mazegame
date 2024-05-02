#ifndef _HEADER_H
#define _HEADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

/* macros */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MAP_WIDTH 32 
#define MAP_HEIGHT 32




/* structure */
/**
 * struct point_s - data structure for XY point coordinates of type double
 * @x: X coordinate
 * @y: Y coordinate
 * Description: struct point in the map space
 */
typedef struct point_s
{
	double x;
	double y;
} point_t;

extern SDL_Window *Window;      /*      Window instance     */
extern SDL_Renderer *Renderer;  /*   Renderer Instance from SDL     */
extern point_t pos;             /*    (x,y) point positon     */
extern point_t axis;            /*     camera plane       */
extern point_t direction;            /* initial direction vector */
extern point_t plane;          /* camera plane */
extern double time;            /* time of current frame */
/* initalize SDL */
bool init_SDL(void);
/* handle user input */
void user_input(int *maze);















































#endif