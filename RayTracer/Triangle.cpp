#include "Triangle.h"

Triangle::Triangle(Vector p1, Vector p2, Vector p3, Vector co, float t, float d, float a, float s)
	: Object(co, t, d, a, s)
{
	t1 = p1;
	t2 = p2;
	t3 = p3;
	normal = crossProductForNormal(p1, p2, p3);
	normal.normalize();
	D = fabsf(normal.x *(-p1.x) + normal.y*(-p1.y) + normal.z*(p1.z));
}

bool Triangle::isHit(Vector & rayVector, Vector & rayOrigin)
{
	float t;
	float check = rayVector.dotProduct(normal);
	if (check >= 0) return false;
	else {
		t = -1 * ((normal.dotProduct(rayOrigin) + D) / check);
		if (t < 0) return false;
	}
	Vector hitP = (rayVector * t) + rayOrigin;
	return (inTriangle(hitP));
}

Vector Triangle::intersectPoints(const Vector & rayVector, const Vector & rayOrigin)
{

	float t;
	float check = rayVector.dotProduct(normal);
	t = -1 * ((normal.dotProduct(rayOrigin) + D) / check);
	Vector hitP = (rayVector * t) + rayOrigin;


	return hitP;
}

Vector Triangle::normalPoint(Vector hitPoint)
{
	return normal;
}

bool Triangle::inTriangle(Vector point)
{
	//vectors
	Vector v0 = t2 - t1;
	Vector v1 = t3 - t1;
	Vector v2 = point - t1;

	float d00, d01, d02, d11, d12;
	d00 = v0.dotProduct(v0);
	d01 = v0.dotProduct(v1);
	d02 = v0.dotProduct(v2);
	d11 = v1.dotProduct(v1);
	d12 = v1.dotProduct(v2);

	float invDenom = 1 / (d00 * d11 - d01 * d01);
	float u = (d11 *d02 - d01 *d12) * invDenom;
	float v = (d00 *d12 - d01 *d02) * invDenom;
	return ((u >= 0) && (v >= 0) && (u + v < 1));
}

Vector Triangle::crossProductForNormal(Vector &p1, Vector &p2, Vector &p3) {
	
	Vector v = p1 - p2;
	Vector w = p3 - p1;
	float Nx = (v.y * w.z) - (v.z * w.y);
	float Ny = (v.z * w.x) - (v.x * w.z);
	float Nz = (v.x * w.y) - (v.y * w.x);
	return Vector(Nx, Ny, Nz);
}
