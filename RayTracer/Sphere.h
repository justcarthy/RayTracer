#pragma once
#include "Object.h"


class Sphere :public Object {
	public:
		float radius;
		Vector center;
		Sphere(Vector c, float r, Vector co, float t, Type s /*Matrix4 x*/);
	
		
		bool isHit(Vector &rayVector, Vector &rayOrigin);
		Vector intersectPoints(const Vector &rayVector, const Vector &rayOrigin);
		Vector normalPoint(Vector hitPoint);
		
	private:
		float calcB(const Vector &rayVector, const Vector &rayOrigin);
		float calcC(const Vector &rayVector, const Vector &rayOrigin);
		float discriminant(float B, float C);

};