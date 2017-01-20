#include "Object.h"

Object::Object(Vector co, float trans, float d, float a, float s)
{
	this->color = co;
	this->transparency = trans;
	this->diffuse = d;
	this->ambient = a;
	this->specular = s;
}
