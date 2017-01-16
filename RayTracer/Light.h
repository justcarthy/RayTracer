#pragma once
#include "Vector.h"

class Light {
public:
	Vector position;
	Vector color;
	Light(Vector p, Vector c) : position(p), color(c) {}
};