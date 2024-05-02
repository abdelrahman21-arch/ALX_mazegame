/*
* file: input.c
* Author: sweilam
*/

#include "headers.h"

/**
 * user_input - handles user input for movement
 * @maze: 2D array defining maze structure
 * Return: None
*/
void user_input(int *maze)
{
    const uint8_t *keystate; /* current key state */
	double oldTime; /* time of previous frame */
	double frameTime; /* time the frame has taken in seconds */
	double oldDirX, oldPlaneX; /* previous dir.x and plane.x */
	double moveSpeed; /* move speed modifier */
	double rotateSpeed; /* rotate speed modifier */

	keystate = SDL_GetKeyboardState(NULL);
	oldTime = time;
	time = SDL_GetTicks();
	frameTime = (time - oldTime) / 1000.0;
	moveSpeed = frameTime * 5.0;
	rotateSpeed = frameTime * 3.0;

    /* move forward if no wall in front found */
	if (keystate[SDL_SCANCODE_UP])
	{
		if (!*((int *)maze + (int)(pos.x + direction.x * moveSpeed)
		       * MAP_WIDTH + (int)pos.y))
			pos.x += direction.x * moveSpeed;
		if (!*((int *)maze + (int)pos.x * MAP_WIDTH +
		       (int)(pos.y + direction.y * moveSpeed)))
			pos.y += direction.y * moveSpeed;
	}

    /* move backward if no wall in back*/
    if(keystate[SDL_SCANCODE_DOWN])
    {
         if (!*((int *)maze + (int)(pos.x - direction.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x -= direction.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y - direction.y * moveSpeed)))
			pos.y -= direction.y * moveSpeed;
    }

    /* strafe-left */
    if (keystate[SDL_SCANCODE_LEFT])
	{
		if (!*((int *)maze + (int)(pos.x - plane.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x -= plane.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y - plane.y * moveSpeed)))
			pos.y -= plane.y * moveSpeed;
	}
    
















































}

