#include "PlayerEntity.h"
#include "ParticleSystem.h"
#include "GausianGenerator.h"
#include "ForceGenerator.h"
PlayerEntity::PlayerEntity(const Vector3 initPos, float size, physx::PxPhysics* gP, EntityManager* em)
{
	mGeo = new physx::PxSphereGeometry(size);
	mtrans = new physx::PxTransform(initPos);
	mshape = CreateShape(*mGeo, gP->createMaterial(0.5,0.5,1));
	mItem = new RenderItem(mshape,mtrans, Vector4(1,0.2,0.4,1));
	RegisterRenderItem(mItem);
	jetPackForce = new ForceGenerator(Vector3(20,0,0));
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::inputListener(unsigned char key)
{

}

bool PlayerEntity::update(double t)
{
    return false;
}
