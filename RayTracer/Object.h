#pragma once

#include "Vector.h"


class Object {
		
	public:
		Vector color;
		Vector center;
		//float translucent, reflect;
	protected:
		Object(const Vector &c, const Vector &co) :  center(c), color(co) {};
};