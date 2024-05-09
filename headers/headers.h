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
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_CHAR_COUNT 1275
#define TEX_COUNT 6




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
/*mapParser*/
int *mapParser(char *filename, int *map);
/* raycaster */
void raycaster(int *maze, bool textured);
void renderWalls(int *maze, SDL_Point map, point_t rayPos, point_t rayDir, double distToWall, int x, int side, bool textured);
void renderBGTex(SDL_Point map, point_t rayDir, double distToWall, double wallX, int drawEnd, int x, int side);
void renderBGFlat(void);
bool quit(void);
void closeSDL(void);















































#endif