#pragma once
#include "Vector.h"

class Camera {
public:
	int width;
	int height;
	float fov;
	float aspectRatio;
	Vector origin;

	Camera(int w, int h, float f) : width(w), height(h), fov(f) {
		width >= height ? aspectRatio = width / float(height) : aspectRatio = height / float(width);
		origin = Vector(0, 0, 0);
	}
	float worldX(float x);
	float worldY(float y);

};