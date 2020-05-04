#ifndef KNAVE_COMMON_H
#define KNAVE_COMMON_H

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
namespace knave {
	GameContext init_game_context() {
		printf("Initialization\n");

		GameContext return_value = { 0 };

		return_value.screen_size.x = SCREEN_WIDTH;
		return_value.screen_size.y = SCREEN_HEIGHT;

		return_value.camera.position = { 0.0f, 300.0f, 500.0f };
		return_value.camera.target = { 0.0f, 0.0f, 0.0f };
		return_value.camera.up = { 0.0f, 1.0f, 0.0f };
		return_value.camera.fovy = 45.0f;
		return_value.camera.type = CAMERA_PERSPECTIVE;

		SetCameraMode(return_value.camera, CAMERA_FREE);

		return return_value;
	}
}
#endif // !KNAVE_COMMON_H
