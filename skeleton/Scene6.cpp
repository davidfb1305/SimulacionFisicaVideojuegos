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
	mEntityManager->createPxBox(Vector3(0, 50, 0),Vector3(100,0,0), Vector3(100, 0, 0), Vector3(1, 1, 1), Vector4(1, 1, 1,1),15);
}

void Scene6::inputListener(unsigned char key, const physx::PxTransform& camera)
{
}
