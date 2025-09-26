#include "Entity.h"

Entity::Entity(physx::PxGeometry* g, physx::PxTransform* t, physx::PxShape* s, RenderItem* r)
{
	mGeo = g;
	mtrans = t;
	mshape = s;
	mItem = r;
}

Entity::Entity()
{
		mtrans = nullptr;
		mItem = nullptr;
		mshape = nullptr;	
}
void
Entity::update(double d) {

}

