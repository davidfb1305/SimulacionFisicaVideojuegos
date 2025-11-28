#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include <list>
class ForceGenerator;
enum MoveType
{
	SemiEuler = 0,
	Euler,
	Valet

};
enum RemoveCondition {
	NONE = 0,
	TIME,
	DISTANCE
};
class Entity
{

protected: 
	MoveType mMt;
	RemoveCondition mRc;
	double timeToRemove;
	physx::PxVec3 initpos;
	physx::PxVec3 maxpos;
	physx::PxVec3 maxdistance;
	bool active = false;
	virtual void addForces();
	std::list<Entity*>* mparentGeneratorList = nullptr;
	std::list<ForceGenerator*> forceList;
public:
	physx::PxGeometry* mGeo;
	physx::PxTransform* mtrans = nullptr;
	physx::PxShape* mshape = nullptr;
	RenderItem* mItem = nullptr;
	

	physx::PxVec3 forceToAdd;
	Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r,std::list<ForceGenerator*> fl = std::list<ForceGenerator*>());
	~Entity();
	Entity();
	void setActive(bool b);
	bool isActive();
	void addForce(Vector3 vec);
	void setForceList(std::list<ForceGenerator*> fl);
	void addForceGenerator(ForceGenerator* fg);
	void removeForceGenerator(ForceGenerator* fg);
	void setParentListPointer(std::list<Entity*>* l);
	void clearForce();
	virtual bool updateDestroyCondition(double t);
	virtual bool update(double t);
};
	

