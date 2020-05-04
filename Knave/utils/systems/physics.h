#ifndef KNAVE_PHYSICS_H
#define KNAVE_PHYSICS_H

#ifdef __cplusplus
extern "C" {
#endif

	//Physics Components 

	typedef struct Speed {
		float value;
	} Speed;

	/*
	typedef struct AngularSpeed {
		float value;
	} AngularSpeed;

	typedef struct Vector3 AngularVelocity;
	*/

	typedef struct Vector2 Position2D;

	typedef struct Vector3 Position3D;

	typedef struct Vector2 Velocity2D;

	typedef struct Vector3 Velocity3D;

	typedef struct Vector2 Size2D;

	typedef struct Vector3 Size3D;

	typedef struct ComponentsPhysics {
		ECS_DECLARE_COMPONENT(Speed);
		ECS_DECLARE_COMPONENT(Position2D);
		ECS_DECLARE_COMPONENT(Position3D);
		ECS_DECLARE_COMPONENT(Size2D);
		ECS_DECLARE_COMPONENT(Size3D);
		ECS_DECLARE_COMPONENT(Velocity2D);
		ECS_DECLARE_COMPONENT(Velocity3D);
	} ComponentsPhysics;

	void Move2D(ecs_rows_t* rows) {
		ECS_COLUMN(rows, Position2D, position, 1);
		ECS_COLUMN(rows, Velocity2D, velocity, 2);

		for (int i = 0; i < rows->count; i++) {
			position[i].x += velocity[i].x;
			position[i].y += velocity[i].y;
		}
	}

	void Move3D(ecs_rows_t* rows) {
		ECS_COLUMN(rows, Position3D, position, 1);
		ECS_COLUMN(rows, Velocity3D, velocity, 2);

		for (int i = 0; i < rows->count; i++) {
			position[i].x += velocity[i].x;
			position[i].y += velocity[i].y;
			position[i].z += velocity[i].z;
		}
	}


	/* dunno if any of this shit is right either
	void ComponentsPhysicsImport(
		ecs_world_t* world,
		int flags
	);

#define ComponentsPhysicsImportHandles(handles)\
	ECS_IMPORT_COMPONENT(handles, Speed);\
	ECS_IMPORT_COMPONENT(handles, Velocity2D);\
	ECS_IMPORT_COMPONENT(handles, Velocity3D);\
	ECS_IMPORT_COMPONENT(handles, AngularSpeed);\
	ECS_IMPORT_COMPONENT(handles, AngularVelocity);\
	*/

	//Physics System


	/*
	typedef struct SystemsPhysics {
		ECS_DECLARE_ENTITY(Move2D_w_Rotation);
		ECS_DECLARE_ENTITY(Move2D_w_Velocity);
		ECS_DECLARE_ENTITY(Move2D);
		ECS_DECLARE_ENTITY(Move3D_w_Rotation);
		ECS_DECLARE_ENTITY(Move3D_w_Rotation);
		ECS_DECLARE_ENTITY(Move3D);
		ECS_DECLARE_ENTITY(Rotate2D);
		ECS_DECLARE_ENTITY(Rotate3D);
		ECS_DECLARE_ENTITY(Move);
		ECS_DECLARE_ENTITY(Collide);
	} SystemsPhysics;

	void SystemsPhysicsImport(
		ecs_world_t* world,
		int flags
	);

#define SystemsPhysicsImportHandles(handles)\
	ECS_IMPORT_ENTITY(handles, Move2D_w_Rotation);\
	ECS_IMPORT_ENTITY(handles, Move2D_w_Velocity);\
	ECS_IMPORT_ENTITY(handles, Move2D);\
	ECS_IMPORT_ENTITY(handles, Move3D_w_Rotation);\
	ECS_IMPORT_ENTITY(handles, Move3D_w_Velocity);\
	ECS_IMPORT_ENTITY(handles, Move3D);\
	ECS_IMPORT_ENTITY(handles, Rotate2D);\
	ECS_IMPORT_ENTITY(handles, Move);\
	ECS_IMPORT_ENTITY(handles, Collide);

	*/
#ifdef __cplusplus
}
#endif 

#endif // !KNAVE_PHYSICS_H
