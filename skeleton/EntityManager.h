#pragma once
#include <list>
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Entity.h"
#include <iostream>
//class Entity


class EntityManager
{
private:
	std::list<Entity*> entityList;
	physx::PxPhysics* gPhysics;
protected:

public:
	EntityManager(physx::PxPhysics* gPh);
	~EntityManager();
	void createAxes();
	Entity* createSphere(const Vector3& transform = Vector3(0,0,0), double r = 1,
	const Vector4& color = Vector4(1.0f,1.0f,1.0f,1.0f), const float& mat1  = 1.0f, const float& mat2 = 1.0f, const float& mat3 = 1.0f);
	Entity* createParticle(const Vector3& transform = Vector3(0, 0, 0), const Vector3& v = Vector3(0, 0, 0), const Vector3& a = Vector3(0, 0, 0), double d = 1,int mt = 0, double r = 1,
		const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), const float& mat1 = 1.0f, const float& mat2 = 1.0f, const float& mat3 = 1.0f);
	void ReleaseEntities();
	void updateEntities(double t);
};

