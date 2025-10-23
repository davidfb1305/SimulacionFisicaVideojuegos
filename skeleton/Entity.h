#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
class Entity
{

protected: 
	bool active = false;
public:
	physx::PxGeometry* mGeo;
	physx::PxTransform* mtrans = nullptr;
	physx::PxShape* mshape = nullptr;
	RenderItem* mItem = nullptr;
	Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r);
	~Entity();
	Entity();
	void setActive(bool b);
	bool isActive();
	virtual bool update(double t);
};

