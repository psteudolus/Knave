#ifndef KNAVE_OPTIONS_H
#define KNAVE_OPTIONS_H

namespace knave {
	namespace options {
		void render(ecs_rows_t* rows) {
			GameContext* game_context = (GameContext*)ecs_get_system_context(rows->world, rows->system);
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RED);
			DrawText("OPTIONS SCREEN", 20, 20, 30, DARKBROWN);
			DrawText("PRESS ENTER to JUMP to TITLE SCREEN", 120, 220, 20, DARKBROWN);
			DrawFPS(5, 5);
			EndDrawing();
		}

		void post_render(ecs_rows_t* rows) {
			GameContext* game_context = (GameContext*)ecs_get_system_context(rows->world, rows->system);

			if (IsKeyPressed(KEY_ENTER)) {
				game_context->world = screens[TITLE];
			}
		}

		void init(ecs_world_t* world, knave::GameContext* game_context) {
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
#endif // !KNAVE_OPTIONS_H
