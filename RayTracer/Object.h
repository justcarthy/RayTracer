#pragma once

#include "Vector.h"
#include "Matrix4.h"
#include "Vector.h"
#include <math.h>

enum Type { SPECULAR, DIFFUSED };

class Object {
		
	public:
		Vector color;
		float transparency;
		Type surface;
		Matrix4 transform;
		Matrix4 inverse;
		Matrix4 transpose;
		Object(Vector co, float trans, Type t);

		virtual bool isHit(Vector & rayVector, Vector& rayOrigin) = 0;
		virtual Vector intersectPoints(const Vector & rayOrigin, const Vector &rayVec) = 0;
		virtual Vector normalPoint(Vector hitPoint) = 0;

};