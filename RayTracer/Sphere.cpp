#include "Sphere.h"

bool Sphere::isHit(Vector & rayVector, Vector & rayOrigin )
{
	float B = calcB(rayVector, rayOrigin);
	float C = calcC(rayVector, rayOrigin);
	if (discriminant(B, C) < 0) return false;
	else return true;

}

Vector Sphere::intersectPoint(Vector & rayVector, Vector & rayOrigin)
{
	float B = calcB(rayVector, rayOrigin);
	float C = calcC(rayVector, rayOrigin);
	
	float t0 = (-B - sqrt(discriminant(B, C))) / 2;
	float t1 = (-B + sqrt(discriminant(B, C))) / 2;
	float tAccept;
	if (t0 > 0) tAccept = t0;
	else tAccept = t1;
	Vector point = rayVector * tAccept;
	point = point + rayOrigin;

	return point;
}

Vector Sphere::normalPoint(Vector & pointOnSphere)
{	
	return (pointOnSphere - center)/radius;
}

float Sphere::calcB(Vector & rayVector, Vector & rayOrigin)
{
	Vector check = rayOrigin - center;
	check = check * rayVector;
	float B = (2 * (check.x + check.y + check.z));
	return B;
}

float Sphere::calcC(Vector & rayVector, Vector & rayOrigin)
{
	Vector temp = rayOrigin - center;
	temp = temp*temp;
	return (temp.x + temp.y + temp.z - powf(radius, 2));
}

float Sphere::discriminant(float B, float C)
{
	return powf(B, 2) - (4 * C);
}
