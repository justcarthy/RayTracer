#pragma once
#include "Object.h"
#include "Vector.h"
#include <math.h>

class Sphere :public Object {
	public:
		float radius;

		Sphere(const Vector &c, const Vector &co, const float & r) : radius(r), Object(c, co) {}
		
		bool isHit(Vector &rayVector, Vector &rayOrigin);
		Vector intersectPoint(Vector &rayVector, Vector &rayOrigin);
		Vector normalPoint(Vector &pointOnSphere);
		
	private:
		float calcB(Vector &rayVector, Vector &rayOrigin);
		float calcC(Vector &rayVector, Vector &rayOrigin);
		float discriminant(float B, float C);

};