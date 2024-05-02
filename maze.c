/*
* file: maze.c
* Author: Sweilam
*/

#include "headers.h"

/* global vars */
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
point_t pos;
point_t direction;
point_t plane;
double time;

/**
 * main - render maze
 * @argc: number of arguments
 * @argv: the array containing arguments
 * Return: 0 on success, 1 on failure
*/
int main(int argc, char* argv[])
{

    int *maze; /*pointer to 2d array containing maze map*/
    char *NameofMap;
    bool textured;
    pos.x = 1;
    pos.y = 2;
    direction.x = 1;
    direction.y = -0.55;
    plane.x = 0;
    plane.y = 0.55;
    time = 0;
    NameofMap = "\0";

    textured = false;
    if (argc == 3 )
    {
        if (strcmp(argv[2], "tex") == 0)
            textured = true;
        NameofMap = argv[1];
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "no_tex") == 0)
            NameofMap = "maps/first_map";
        else
        {
            NameofMap = argv[1];
        }

    }
    else if (argc == 1)
    {
        NameofMap = "maps/first_map";
    }
    if (!init_SDL())
        return (1);
    maze = NULL;
    maze = mapParser(NameofMap, maze);
    if (maze == NULL)
    {
        printf("Cannot load map");
        return (1);
    }

    while(true)
    {
        if(!textured)
            renderBGFlat();
        
        raycaster(maze, textured);
        
        user_input(maze);

    }
    /*clean up */
    closeSDL();
    free(maze);
    return (0);





    
}