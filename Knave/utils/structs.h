#ifndef KNAVE_STRUCTS_H
#define KNAVE_STRUCTS_H

namespace knave {
	enum GameScreens {
		LOGO = 0,
		TITLE,
		OPTIONS,
		GAMEPLAY,
		ENDING,
		SCREEN_COUNT
	};

	typedef struct game_context_t {
		Vector2 screen_size;
		Camera3D camera;
		ecs_world_t* world;
	} game_context_t;

	typedef struct renderable_t {
		Vector3 position;
		void* asset;
		int asset_type;
	} renderable_t;

	/*
	typedef	struct sp_asset_t {
		spAtlas* atlas;
		spSkeletonJson* json;
		spSkeletonData* skeletonData;
		spSkeleton* skeleton;
		spAnimationStateData* animationStateData;
		spAnimationState* animationState;
	} sp_asset_t;
	*/

}

#endif // !KNAVE_STRUCTS_H
