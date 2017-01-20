#pragma once
#include "Vector.h"
//TODO make this an object
class Light {
public:
	Vector position;
	Vector color;
	Light(Vector p, Vector c) : position(p), color(c) {}
};