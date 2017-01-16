#include "Object.h"

Object::Object(Vector co, float trans, Type t)
{
	this->color = co;
	this->transparency = trans;
	this->surface = t;
}
