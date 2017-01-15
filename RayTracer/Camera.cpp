#include "Camera.h"
#define M_PI 3.141592
float Camera::worldX(float x)
{
	float wx = (2 * ((x + 0.5) / width) - 1) * tan(fov / 2 * M_PI / 180) * aspectRatio;
	return wx;
}

float Camera::worldY(float y)
{
	float wy = (1 - 2 * ((y + 0.5) / height) * tan(fov / 2 * M_PI / 180));
	return wy;
}
