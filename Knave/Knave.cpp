// Knave.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <SDL2/SDL.h>
#include "flecs.h"

/*
bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gHelloWorld = NULL;
*/

int main(int argc, char* argv[]) {
	ecs_world_t* world = ecs_init_w_args(argc, argv);
	/* Set target FPS for main loop */
	ecs_set_target_fps(world, 120);

	printf("Application test_app is running, press CTRL-C to exit...\n");

	/* Run systems */
	while (ecs_progress(world, 0));

	/* Cleanup */
	return ecs_fini(world);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
