#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(float x, float y, float z)
{
	v3[0] = x;
	v3[1] = y;
	v3[2] = z;
}

Vector3D Vector3D::operator+(Vector3D aux)
{
	return Vector3D(v3[0]+aux.v3[0], v3[1] + aux.v3[1], v3[2] + aux.v3[2]);
}

Vector3D Vector3D::operator-(Vector3D aux)
{
	return Vector3D(v3[0] - aux.v3[0], v3[1] - aux.v3[1], v3[2] - aux.v3[2]);
}

Vector3D Vector3D::operator*(Vector3D aux)
{
	return Vector3D(v3[0] * aux.v3[0] , v3[1] * aux.v3[1], v3[2] *aux.v3[2]);
}

void Vector3D::operator=(Vector3D aux)
{
	v3[0] = aux.v3[0];
	v3[1] = aux.v3[1];
	v3[2] = aux.v3[2];
}

Vector3D Vector3D::x(float aux)
{
	return Vector3D();
}

float Vector3D::module()
{
		return std::sqrt(v3[0] * v3[0] + v3[1] * v3[1] + v3[2] * v3[2]);
}
