#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
class Entity
{
public:
	physx::PxGeometry* mGeo;
	physx::PxTransform* mtrans = nullptr;
	physx::PxShape* mshape = nullptr;
	RenderItem* mItem = nullptr;
	Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r);
	Entity();
	virtual bool update(double t);
};

