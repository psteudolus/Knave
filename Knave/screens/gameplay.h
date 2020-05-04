#ifndef KNAVE_GAMEPLAY_H
#define KNAVE_GAMEPLAY_H

namespace knave {
	namespace gameplay {

		void update(ecs_rows_t* rows) {
			GameContext* game_context = (GameContext*)ecs_get_system_context(rows->world, rows->system);

			Move3D(rows);
			UpdateCamera(&game_context->camera);
		}

		void render(ecs_rows_t* rows) {
			GameContext* game_context = (GameContext*)ecs_get_system_context(rows->world, rows->system);

			ECS_COLUMN(rows, Position3D, position, 1);
			ECS_COLUMN(rows, Size3D, size, 2);

			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PURPLE);

			BeginMode3D(game_context->camera);
				for (int i = 0; i < rows->count; i++) {
					DrawCubeV(position[i], size[i], RED);
					DrawCubeWiresV(position[i], size[i], BLACK);
				}

			EndMode3D();
			DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
			DrawText("PRESS ENTER to JUMP to ENDING SCREEN", 120, 220, 20, MAROON);
			DrawFPS(5, 5);
			EndDrawing();
		}

		static void player_input(ecs_rows_t* rows) {
			//Position3D, Size3D,
			//ECS_COLUMN(rows, Position3D, position, 1);
			//ECS_COLUMN(rows, Size3D, size, 2);
			ECS_COLUMN(rows, Velocity3D, velocity, 1);
			GameContext* game_context = (GameContext*)ecs_get_system_context(rows->world, rows->system);
			
			if (IsKeyPressed(KEY_ENTER)) {
				game_context->world = screens[ENDING];
			}
			for (int i = 0; i < rows->count; i++) {

				if (IsKeyDown(KEY_UP)) {
					velocity[i].y = 1;
				}
				else if (IsKeyDown(KEY_DOWN)) {
					velocity[i].y = -1;
				}
				else {
					velocity[i].y = 0;
				}
				if (IsKeyDown(KEY_LEFT)) {
					velocity[i].x = -1;
				}
				else if (IsKeyDown(KEY_RIGHT)) {
					velocity[i].x = 1;
				}
				else {
					velocity[i].x = 0;
				}
			}
		}

		void init_box(ecs_rows_t* rows) {
			ECS_COLUMN(rows, Position3D, position, 1);
			ECS_COLUMN(rows, Velocity3D, velocity, 2);
			ECS_COLUMN(rows, Size3D, size, 3);

			for (int i = 0; i < rows->count; i++) {
				position[i].x = 40;
				position[i].y = 40;
				position[i].z = 0;
				velocity[i].x = 0;
				velocity[i].y = 0;
				velocity[i].z = 0;
				size[i].x = 50;
				size[i].y = 50;
				size[i].z = 50;
			}
		}

		void init(ecs_world_t* world, GameContext* game_context) {
			ECS_COMPONENT(world, Position3D);
			ECS_COMPONENT(world, Velocity3D);
			ECS_COMPONENT(world, Size3D);
			ECS_TAG(world, tag_ui);

			ECS_SYSTEM(world, init_box, EcsOnAdd, Position3D, Velocity3D, Size3D);


			ECS_TYPE(world, MyBox, Position3D, Velocity3D, Size3D, tag_ui);
			ecs_new_w_count(world, MyBox, 1);

			ECS_SYSTEM(world, update, EcsOnUpdate, Position3D, Velocity3D);
			ecs_set_system_context(world, update, game_context);

			ECS_SYSTEM(world, render, EcsOnUpdate, Position3D, Size3D);
			ecs_set_system_context(world, render, game_context);

			ECS_SYSTEM(world, player_input, EcsOnUpdate, Velocity3D, tag_ui);
			ecs_set_system_context(world, player_input, game_context);
			ecs_new(world, tag_ui);

			ecs_set_target_fps(world, 100);
		}
	}
}
#endif // !KNAVE_GAMEPLAY_H
