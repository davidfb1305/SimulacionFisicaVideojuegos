#include "Entity.h"

Entity::Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r)
{
	mGeo = g;
	mtrans = t;
	mshape = s;
	mItem = r;
	active = true;
}

Entity::~Entity()
{
	DeregisterRenderItem(mItem);
	delete mtrans;
	delete mItem;
	delete mGeo;
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
}
bool
Entity::update(double d) {
	return false;
}

