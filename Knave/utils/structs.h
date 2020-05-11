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

	typedef struct GameContext {
		Vector2 screen_size;
		Camera3D camera;
		ecs_world_t* world;
	} GameContext;

	/*	this shouldn't be in a single component
		renderable tagged systems will process entities with the asset componen and position component
	*/

	//rendering

	/*
	typedef struct Asset {
		//Vector3 position;
		void* asset;
		int asset_type;
	} Asset;
	*/

	//gameplay

	typedef struct Health {
		int health;
	} Health;

	typedef struct Input {
		//not sure how to structure an input component
	} Input;

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
