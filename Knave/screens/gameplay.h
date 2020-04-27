#ifndef KNAVE_GAMEPLAY_H
#define KNAVE_GAMEPLAY_H

namespace knave {
	namespace gameplay {
		void render(ecs_rows_t* rows) {
			game_context_t* game_context = (game_context_t*)ecs_get_system_context(rows->world, rows->system);
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PURPLE);
			DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
			DrawText("PRESS ENTER to JUMP to ENDING SCREEN", 120, 220, 20, MAROON);
			DrawFPS(5, 5);
			EndDrawing();
		}

		static void post_render(ecs_rows_t* rows) {
			game_context_t* game_context = (game_context_t*)ecs_get_system_context(rows->world, rows->system);
			
			if (IsKeyPressed(KEY_ENTER)) {
				game_context->world = screens[ENDING];
			}
		}

		void init(ecs_world_t* world, game_context_t* game_context) {
			ECS_COMPONENT(world, Vector3);
			ECS_TAG(world, tag_renderable);
			ECS_TAG(world, tag_ui);

			ECS_SYSTEM(world, render, EcsOnUpdate, tag_renderable);
			ecs_set_system_context(world, render, game_context);
			ecs_new(world, tag_renderable);

			ECS_SYSTEM(world, post_render, EcsOnUpdate, tag_ui);
			ecs_set_system_context(world, post_render, game_context);
			ecs_new(world, tag_ui);

			ecs_set_target_fps(world, 100);
		}
	}
}
#endif // !KNAVE_GAMEPLAY_H
