#pragma once
class Vector3D
{
private:
	float v3[3];
public:
	Vector3D(float x = 0, float y = 0, float z = 0);
	Vector3D operator+(Vector3D aux);
	Vector3D operator-(Vector3D aux);
	Vector3D operator*(Vector3D aux);
	void operator=(Vector3D aux);
	Vector3D x(float aux);
	float module();

};

