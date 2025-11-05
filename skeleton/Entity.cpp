#include "Entity.h"
#include "ForceGenerator.h"
Entity::Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r, std::list<ForceGenerator*> fl)
{
	mGeo = g;
	mtrans = t;
	mshape = s;
	mItem = r;
	active = true;
	forceList = fl;
	forceToAdd = Vector3(0, 0, 0);
}

Entity::~Entity()
{
	if(mItem!=nullptr)
	DeregisterRenderItem(mItem);
}
bool Entity::isActive() {
	return active;
}
void Entity::setActive(bool b) {

	active = b;
}
Entity::Entity()
{
		mtrans = nullptr;
		mItem = nullptr;
		mshape = nullptr;	
		forceToAdd = Vector3(0, 0, 0);
}
bool
Entity::update(double d) {
	return false;
}

void Entity::addForces()
{
}

void Entity::addForce(Vector3 vec)
{
	forceToAdd += vec;
}

void Entity::setForceList(std::list<ForceGenerator*> fl)
{
	forceList = fl;
}

void Entity::addForceGenerator(ForceGenerator* fg)
{
	forceList.push_back(fg);
}

void Entity::removeForceGenerator(ForceGenerator* fg)
{
	forceList.remove(fg);
}

void Entity::clearForce()
{
	forceToAdd = Vector3(0, 0, 0);
}

