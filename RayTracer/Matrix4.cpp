#include "Matrix4.h"

Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++) {
		matrix[i][i] = 1;
	}
}

Vector Matrix4::matmul(Vector v)
{	
	Vector result;

	result.x = v.dotProduct(Vector(matrix[0][0], matrix[0][1], matrix[0][2]))+ matrix[0][3];
	result.y = v.dotProduct(Vector(matrix[1][0], matrix[1][1], matrix[1][2])) + matrix[1][3];
	result.z = v.dotProduct(Vector(matrix[2][0], matrix[2][1], matrix[2][2])) + matrix[2][3];
	return result;
}

void Matrix4::rotate(int axis, float angle)
{
	switch (axis)
	{
	case 0: //x -axis
		matrix[1][1] = cos(angle);
		matrix[2][2] = matrix[1][1];
		matrix[1][2] = -1 * sin(angle);
		matrix[2][1] = -1 * matrix[1][2];
		break;
	case 1://y-axis
		matrix[0][0] = cos(angle);
		matrix[2][2] = matrix[0][0];
		matrix[0][2] = sin(angle);
		matrix[2][0] = -1 * matrix[0][2];
	case 2://z-axis
		matrix[0][0] = cos(angle);
		matrix[1][1] = matrix[0][0];
		matrix[0][1] = -1 * sin(angle);
		matrix[1][0] = -1 * matrix[0][1];
		break;
	default:
		break;
	}
}

void Matrix4::translate(Vector direction) 
{
	matrix[0][3] = direction.x;
	matrix[1][3] = direction.y;
	matrix[2][3] = direction.z;
	matrix[3][3] = 1;
}

Matrix4 Matrix4::operator*(const Matrix4 & mat) const
{

	Matrix4 result;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (i == j) result.matrix[i][j]--;
			for (int k = 0; k<4; k++) {
				result.matrix[i][j] += matrix[i][k] * mat.matrix[k][j];
			}
		}
	}
	return result;
}
