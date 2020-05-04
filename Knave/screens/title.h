#ifndef KNAVE_TITLE_H
#define KNAVE_TITLE_H

namespace knave {
	namespace title {
		static void render(ecs_rows_t* rows) {
			GameContext* game_context = (GameContext*) ecs_get_system_context(rows->world, rows->system);
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GREEN);
			DrawText("TITLE SCREEN", 20, 20, 30, DARKGREEN);
			DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
			DrawFPS(5, 5);
			EndDrawing();
		}

		void post_render(ecs_rows_t* rows) {
			GameContext* game_context = (GameContext*)ecs_get_system_context(rows->world, rows->system);

			if (IsKeyPressed(KEY_ENTER)) {
				game_context->world = screens[GAMEPLAY];
			}
			if (IsKeyPressed(KEY_O)) {
				game_context->world = screens[OPTIONS];
			}
		}

		void init(ecs_world_t* world, GameContext* game_context) {
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

#endif // !KNAVE_TITLE_H