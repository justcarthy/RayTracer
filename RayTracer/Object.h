#pragma once

#include "Vector.h"
#include "Matrix4.h"
#include "Vector.h"
#include <math.h>


class Object {
		
	public:
		Vector color;
		float transparency;
		float diffuse;
		float ambient;
		float specular;

		Matrix4 transform;
		Matrix4 inverse;
		Matrix4 transpose;
		Object(Vector co, float trans, float d, float a, float s);

		virtual bool isHit(Vector & rayVector, Vector& rayOrigin) = 0;
		virtual Vector intersectPoints(const Vector & rayOrigin, const Vector &rayVec) = 0;
		virtual Vector normalPoint(Vector hitPoint) = 0;

};