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
	Vector temp = (*this) - b;
	return (sqrtf(powf(temp.x, 2) + powf(temp.y, 2) + powf(temp.z, 2)));
}

