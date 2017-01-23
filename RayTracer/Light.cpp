#include "Light.h"

////Light::Light(Vector p, Vector c, float t, float d, float a, float s)
////	: Object(c, t, d, a, s)
////{
//	this->position = p;
//}

bool Light::isHit(Vector & rayVector, Vector & rayOrigin)
{

	return false;
}

Vector Light::intersectPoints(const Vector & rayVector, const Vector & rayOrigin)
{
	return Vector(0,0,0);
}

Vector Light::normalPoint(Vector hitPoint)
{
	return Vector();
}

