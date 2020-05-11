#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//global variables local to this module
	Matrix IdentityMatrix = MatrixIdentity();

	//Transform Components
	typedef Vector3 Translate3D;

	typedef Vector3 Scale3D;

	//(yaw, pitch, roll)
	typedef Vector3 Rotation3D;

	typedef float AngularRotation3D;

	typedef Matrix TransformMatrix3D;

	//Transform Systems

	void AddTransformMatrix(ecs_rows_t* rows) {
		ecs_world_t* world = rows->world;
		ecs_entity_t ecs_entity(TransformMatrix3D) = ecs_column_entity(rows, 2);

		for (int i = 0; i < rows->count; i++) {
			ecs_set_ptr(world, rows->entities[i], TransformMatrix3D, &IdentityMatrix);
		}
	}

	//this representation doesn't really match my data, at least i don't think
	//i imagined rotation3d being a vector containing current rx, ry, and rz values
	//aaahhhhhh, i see. i would use rlgl or opengl to actually apply these generated matrices to the objects
	//i think i will need 
	void ApplyTransform3D(ecs_rows_t* rows) {
		ECS_COLUMN(rows, TransformMatrix3D, m, 1);
		ECS_COLUMN(rows, Translate3D, t, 2);
		ECS_COLUMN(rows, Position3D, p, 3);
		ECS_COLUMN(rows, Rotation3D, r, 4);
		ECS_COLUMN(rows, Quaternion, q, 5);
		ECS_COLUMN(rows, Scale3D, s, 6);
		ECS_COLUMN(rows, TransformMatrix3D, m_parent, 7);

		int i;

		//cascading for child entities
		if (!m_parent) { //no parent, set matrix to identity matrix
			for (i = 0; i < rows->count; i++) {
				m[i] = IdentityMatrix;
			}
		}
		else { //if parent, set to pointer to parent so we only have to manipulate the primary matrix
			for (i = 0; i < rows->count; i++) {
				m[i] = *m_parent;
			}
		}

		//Translate
		//translate the default identity matrix by position
		//unsure how these constructed transform matrices are applied to input vector after
		//matrix transformation, should take into account child entities
		if (!ecs_is_shared(rows, 2)) {
			//if position not shared between entities
			//TODO - read more about the difference between shared and non shared components
		}
		else {
			//if position component shared between entities
			for (i = 0; i < rows->count; i++) {
				m[i] = MatrixTranslate(p->x, p->y, p->z);
			}
		}

		//Rotate by vector
		if (r) {
			for (i = 0; i < rows->count; i++) {
				Matrix rotateMatrix = MatrixRotateXYZ(*r);
				m[i] = MatrixMultiply(rotateMatrix, m[i]);
			}
		}

		//Rotate by Quaternion (x, y, z, a)
		if (q) {
			for (i = 0; i < rows->count; i++) {
				Vector3 axis;
				float angle;
				QuaternionToAxisAngle(*q, &axis, &angle);

				Matrix rotateMatrix = MatrixRotate(axis, angle);
				m[i] = MatrixMultiply(rotateMatrix, m[i]);
			}
		}

		//Scale
		if (s) {
			for (i = 0; i < rows->count; i++) {
				Matrix scaleMatrix = MatrixScale(s->x, s->y, s->z);
				m[i] = MatrixMultiply(scaleMatrix, m[i]);
			}
		}
	}


#ifdef __cplusplus
}
#endif // __cplusplus