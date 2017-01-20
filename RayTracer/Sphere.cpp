#include "Sphere.h"

Sphere::Sphere(Vector c, float r, Vector co, float t, float d, float a, float s /*, Matrix4 x*/)
	:Object(co, t, d, a, s)
{
	//this->transform = x;
	this->center = c;
	this->radius = r;
	
}

bool Sphere::isHit(Vector & rayVector, Vector & rayOrigin )
{
	float B = calcB(rayVector, rayOrigin);
	float C = calcC(rayVector, rayOrigin);
	if (discriminant(B, C) < 0) return false;
	else return true;

}

Vector Sphere::intersectPoints(const Vector & rayVector, const Vector & rayOrigin)
{
	float B = calcB(rayVector, rayOrigin);
	float C = calcC(rayVector, rayOrigin);
	
	float t0 = (-B - sqrt(discriminant(B, C))) / 2;
	float t1 = (-B + sqrt(discriminant(B, C))) / 2;
	float tAccept;

	t0 < t1 ? tAccept = t0 : tAccept = t1;
	Vector point = rayVector * tAccept;
	point = point + rayOrigin;

	return point;
}

Vector Sphere::normalPoint(Vector hitPoint)
{	
	return ((hitPoint - center)/radius).normalize();
}

float Sphere::calcB(const Vector & rayVector, const Vector & rayOrigin)
{
	Vector check = rayOrigin - center;
	check = check * rayVector;
	float B = (2 * (check.x + check.y + check.z));
	return B;
}

float Sphere::calcC(const Vector & rayVector, const Vector & rayOrigin)
{
	Vector temp = rayOrigin - center;
	temp = temp*temp;
	return (temp.x + temp.y + temp.z - powf(radius, 2));
}

float Sphere::discriminant(float B, float C)
{
	return powf(B, 2) - (4 * C);
}
