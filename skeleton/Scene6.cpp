#include "Scene6.h"
#include "pxBoxGausianGenerator.h"
#include "EntitySystem.h"
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
	EntitySystem* aux = new EntitySystem(mEntityManager);
	aux->setActive(true);
	pxBoxGausianGenerator* boxgen = new pxBoxGausianGenerator(mEntityManager,Vector3(0.0,50.0,0.0),Vector3(5,5,5),Vector3(0,10,0)
	,Vector3(2,2,2),Vector3(1.0,0.0,0.0),Vector3(5.0,0.0,0.0),Vector3(1.0,1.0,1.0),Vector3(0.0,0.0,0.0), 
		10, 1, Vector4(0.6, 0.4, 0.5, 1.0), Vector4(0.0, 0.4, 0.1, 0.0), Vector3(1.0, 1.0, 1.0), Vector3(0.5, 0.5, 0.5), 50.0, 10, 150);
	aux->addGenerator(boxgen);
	mEntityManager->addEntity(aux);

	//mEntityManager->createPxBox(Vector3(0, 50, 0),Vector3(1,0,0), Vector3(1, 0, 1), Vector3(0.5, 0.5, 0.5), Vector3(5,5, 5), Vector4(0.0, 1, 0.0, 1), 10.0);
}

void Scene6::inputListener(unsigned char key, const physx::PxTransform& camera)
{
}
