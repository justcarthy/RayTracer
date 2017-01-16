#pragma once
#include "Object.h"
#include "Plane.h"

class Triangle : public Object {
public:
	Vector t1;
	Vector t2;
	Vector t3;
	Vector normal;
	Vector hitP;
	float D;

	Triangle(Vector p1, Vector p2, Vector p3, Vector normal, Vector co, float t, Type s);
	bool isHit(Vector &rayVector, Vector &rayOrigin);
	Vector intersectPoints(const Vector &rayVector, const Vector &rayOrigin);
	Vector normalPoint(Vector hitPoint);


private:
	bool inTriangle(Vector point);
};