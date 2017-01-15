#include "Vector.h"

Vector& Vector::normalize() {
	float normal = 1 / magnitude();
	x *= normal; y *= normal; z *= normal;
	return *this;
}

float Vector::magnitude()
{
	float mag = x*x + y*y + z*z;
	if (mag > 0) {
		return sqrtf(mag);
		
	}
	return 0.0f;
}
