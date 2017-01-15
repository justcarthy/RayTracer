#include "Matrix4.h"

Matrix4::Matrix4()
{
	matrix[0] = { 1, 0, 0, 0 };
	matrix[1] = { 0, 1, 0, 0 };
}

Vector & Matrix4::matmul(Vector)
{	
	// TODO: insert return statement here
}

void Matrix4::rotate(int axis, float angle)
{
}

void Matrix4::translate(int axis, float distance)
{
}
