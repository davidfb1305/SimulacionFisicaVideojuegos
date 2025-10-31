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
	std::list<Entity*> entityListToRemove;
	physx::PxPhysics* gPhysics;
protected:

public:
	EntityManager(physx::PxPhysics* gPh);
	~EntityManager();
	void createAxes();
	Entity* createSphere(const Vector3& transform = Vector3(0,0,0), double r = 1,
	const Vector4& color = Vector4(1.0f,1.0f,1.0f,1.0f), const float& mat1  = 1.0f, const float& mat2 = 1.0f, const float& mat3 = 1.0f);
	
	Entity* createParticle(const Vector3& transform = Vector3(0, 0, 0), const Vector3& v = Vector3(0, 0, 0), const Vector3& a = Vector3(0, 0, 0), double d = 1,int mt = 0, double r = 1,
		int rc = 0, int rct = 0, Vector3 maxdis = Vector3(0.0, 0.0, 0.0),
		const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), const float& mat1 = 1.0f, const float& mat2 = 1.0f, const float& mat3 = 1.0f);
	
	Entity* createMassParticle(const Vector3& transform = Vector3(0, 0, 0), const Vector3& v = Vector3(0, 0, 0), const Vector3& vr = Vector3(1.0, 1.0, 1.0),double ms = 1.0 ,const Vector3& a = Vector3(0, 0, 0), double d = 1, int mt = 0, double r = 1,
		int rc = 0, int rct = 0, Vector3 maxdis = Vector3(0.0, 0.0, 0.0),
		const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), const float& mat1 = 1.0f, const float& mat2 = 1.0f, const float& mat3 = 1.0f);


	Entity* createBullet(const Vector3& transform = Vector3(0, 0, 0), const Vector3& v = Vector3(0, 0, 0), const Vector3& a = Vector3(0, 0, 0), double d = 1, int mt = 0, double r = 1,
		int rc = 0, int rct = 0, Vector3 maxdis = Vector3(0.0, 0.0, 0.0),
		const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), const float& mat1 = 1.0f, const float& mat2 = 1.0f, const float& mat3 = 1.0f,
		const physx::PxVec3& vrreal = physx::PxVec3(0.0, 0.0, 0.0), double m = 0, const physx::PxVec3& g = Vector3(0.0, 0.0, 0.0));
	const std::list<Entity*>& getEntityList();
	void ReleaseEntities();
	void addEntity(Entity* e);
	void updateEntities(double t);
};

