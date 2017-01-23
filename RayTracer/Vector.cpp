#include "Vector.h"

Vector& Vector::normalize() {
	float normal = 1 / magnitude();
	x *= normal; y *= normal; z *= normal;
	return *this;
}

float Vector::dotProduct(const Vector & v) const
{
	return (v.x*x + v.y * y + v.z *z);
}


float Vector::magnitude()
{
	float mag = x*x + y*y + z*z;
	if (mag > 0) {
		return sqrtf(mag);
		
	}
	return 0.0f;
}

float Vector::Distance(Vector& b) {
	float dx = x - b.x;
	float dy = y - b.y;
	float dz = z - b.z;
	return sqrtf(dx * dx + dy * dy + dz * dz);
}

