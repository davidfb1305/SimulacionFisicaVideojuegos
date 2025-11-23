#include "Scene6.h"

Scene6::Scene6(physx::PxPhysics* gPh, physx::PxScene* gScene) : SceneTemplate(gPh,gScene)
{
}

Scene6::~Scene6()
{
}

void Scene6::loadScene()
{
	mEntityManager = new EntityManager(gPh, _gScene);
	mEntityManager->createPxPlane();
}

void Scene6::inputListener(unsigned char key, const physx::PxTransform& camera)
{
}
