#include "InitScene.h"
#include "PxPhysicsAPI.h"
#include "PlayerEntity.h"
#include "GravityForceGen.h"
#include "EntitySystem.h"
#include "GausianGenerator.h"
#include "pxBoxGausianGenerator.h"
#include "uniformGenerator.h"
#include "RigidStatic.h"
#include "TimerEntitySystem.h"
#include "SceneManager.h"
InitScene::InitScene(physx::PxPhysics* gPh, physx::PxScene* gScene, SceneManager* sManager,int* bt)
	:SceneTemplate(gPh,gScene)
{
	sm = sManager;
	bestTime = bt;
}


void InitScene::loadScene()
{
	mEntityManager = new EntityManager(gPh, _gScene);
	GravityForceGen* g = new GravityForceGen();
	player = mEntityManager->createPlayer(Vector3(0, 10, 0), 5, gPh);
	_gScene->setSimulationEventCallback(player);
	player->addForceGenerator(g);
	//create the planes
	RigidStatic* a = mEntityManager->createPxPlane();
	player->addToIgnoreList(a->getRigidStatic());
	
	//Rain gausian
	EntitySystem* rain = new EntitySystem(mEntityManager);

	rain->addGenerator(new particleUniformGenerator(mEntityManager, Vector3(0.0, 100.0, 0.0), Vector3(300.1, 0.1, 300.1),
		Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0, 0, 0), Vector4(0.0, 0.0, 1.0, 1.0), Vector4(0, 0, 0.5, 0), 1, 100));
	mEntityManager->addEntity(rain);
	rain->addGenForce(g);
	rain->setActive(true);
	display_text = "PRESIONA A PARA COMENZAR     MEJOR TIEMPO = "+ std::to_string(*bestTime);
}

void InitScene::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	player->inputListener(key);
	switch (toupper(key))
	{
	case 'V':
		;
		mEntityManager->createBullet(camera.p, GetCamera()->getDir() * 50.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 1.0, 1, 10, Vector3(0, 0, 0),
			Vector4(1.0f, 1.0f, 0.0f, 1.0f), 1, 1, 1, Vector3(500.0, 0.0, 0.0), 1.0, Vector3(0.0, -9.81, 0.0));
		break;
	case 'B':
		mEntityManager->createBullet(camera.p, GetCamera()->getDir() * 10.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 2.0, 1, 10, Vector3(0, 0, 0),
			Vector4(1.0f, 0.0f, 1.0f, 1.0f), 1, 1, 1, Vector3(500.0, 0.0, 0.0), 1.0, Vector3(0.0, -9.81, 0.0));
		break;
	case 'A':
		sm->nextScene();
		break;
	}
}

InitScene::~InitScene()
{
}
