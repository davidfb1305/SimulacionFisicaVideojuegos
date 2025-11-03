#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <list>
class ForceGenerator;
class Entity
{

protected: 
	bool active = false;
	virtual void addForces();
	std::list<ForceGenerator*> forceList;
public:
	physx::PxGeometry* mGeo;
	physx::PxTransform* mtrans = nullptr;
	physx::PxShape* mshape = nullptr;
	RenderItem* mItem = nullptr;
	

	physx::PxVec3 forceToAdd;
	Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r,std::list<ForceGenerator*> fl);
	~Entity();
	Entity();
	void setActive(bool b);
	bool isActive();
	void addForce(Vector3 vec);
	void setForceList(std::list<ForceGenerator*> fl);
	void addForceGenerator(ForceGenerator* fg);
	void removeForceGenerator(ForceGenerator* fg);
	void clearForce();

	virtual bool update(double t);
};
	

