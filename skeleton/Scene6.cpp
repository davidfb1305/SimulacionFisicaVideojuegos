#include "Scene6.h"
#include "pxBoxGausianGenerator.h"
#include "BuoyancyForceGenerator.h"
#include "windGenerator.h"
#include "RigidDynamic.h"
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
	//mEntityManager->createPxPlane(Vector3(0,10,0),Vector3(10,0.0001,10));
	EntitySystem* aux = new EntitySystem(mEntityManager);
	aux->setActive(true);
	Entity* plane = mEntityManager->createPlane(Vector3(1, 1, 1), Vector3(1000, 0.001, 1000), Vector4(0.0, 0.0, 1.0, 1.0));
	//forceGenerators
	BuoyancyForceGenerator* auxgen = new BuoyancyForceGenerator(plane, 10, 1000, 1000, 9.8);
	aux->addGenForce(auxgen);
	wind = new windGenerator(Vector3(50.0,0.0,0.0),1.0);
	aux->addGenForce(wind);

	pxBoxGausianGenerator* boxgen = new pxBoxGausianGenerator(mEntityManager,Vector3(0.0,50.0,0.0),Vector3(5,5,5),Vector3(0,10,0)
	,Vector3(2,2,2),Vector3(1.0,0.0,0.0),Vector3(5.0,0.0,0.0),Vector3(1.0,0.5,1.0),Vector3(0.0,3.0,0.0), 
		25000, 100, Vector4(0.6, 0.4, 0.5, 1.0), Vector4(0.0, 0.4, 0.1, 0.0), Vector3(1.0, 1.0, 1.0), Vector3(0.5, 0.5, 0.5), 10.0, 1,150,0.6,0.999);
	aux->addGenerator(boxgen);
	mEntityManager->addEntity(aux);
	
	//RigidDynamic* a =mEntityManager->createPxBox(Vector3(0, 50, 0),Vector3(1,0,0), Vector3(1, 0, 1), Vector3(0.5, 0.5, 0.5), Vector3(5,5, 5), Vector4(0.0, 1, 0.0, 1), 1000.0);
	//a->addForceGenerator(auxgen);
}

void Scene6::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'F':
		wind->setActive(!wind->isActive());
		break;
	}
}
