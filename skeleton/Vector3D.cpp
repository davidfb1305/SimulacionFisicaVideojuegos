#include "Vector3D.h"

Vector3D::Vector3D(float x, float y, float)
{
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
	return Vector3D();
}

Vector3D Vector3D::x(float aux)
{
	return Vector3D();
}
