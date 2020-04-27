// Knave.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <flecs.h>
#include "raylib.h"
#include "utils/structs.h"
#include "utils/common.h"

ecs_world_t* screens[knave::SCREEN_COUNT] = { 0 };

//screens
#include "screens/logo.h"
#include "screens/title.h"
#include "screens/options.h"
#include "screens/gameplay.h"
#include "screens/ending.h"

knave::game_context_t game_context = { 0 };


int main(int argc, char* argv[]) {

	// TODO - Initialize all required variables and load all required data here
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "KNAVE");

	for (int i = 0; i < knave::SCREEN_COUNT; i++) {
		screens[i] = ecs_init_w_args(argc, argv);
	}

	SetTargetFPS(100);

	game_context = knave::init_game_context();

	knave::logo::init(screens[knave::LOGO], &game_context);
	knave::title::init(screens[knave::TITLE], &game_context);
	knave::options::init(screens[knave::OPTIONS], &game_context);
	knave::gameplay::init(screens[knave::GAMEPLAY], &game_context);
	knave::ending::init(screens[knave::ENDING], &game_context);

	game_context.world = screens[knave::LOGO];

	while (ecs_progress(game_context.world, 0) && !WindowShouldClose());

	ecs_fini(screens[0]);

	CloseWindow();		// Close window and OpenGL context

	return 0;

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
