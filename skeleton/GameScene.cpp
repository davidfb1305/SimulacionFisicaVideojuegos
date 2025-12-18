#include "GameScene.h"
#include "PxPhysicsAPI.h"
#include "PlayerEntity.h"
#include "GravityForceGen.h"
#include "EntitySystem.h"
#include "GausianGenerator.h"
#include "pxBoxGausianGenerator.h"
#include "uniformGenerator.h"
#include "RigidStatic.h"
#include "windGenerator.h"
#include "WindTimerGenerator.h"
#include "TimerEntitySystem.h"
#include "SceneManager.h"
GameScene::GameScene(physx::PxPhysics* gPh,physx::PxScene* gScene, SceneManager* smanager, int* bt) :SceneTemplate(gPh,gScene)
{
	sm = smanager;
	bestTime = bt;
}

GameScene::~GameScene()
{
}

void GameScene::update(double t)
{
	
	mEntityManager->updateEntities(t);
	///TODO LIMITAR LA SUBIDA DEL JETPACK POR DEBAJO Y POR ARRIBA
	timerWind->updateWindForce(t);
	actTime += t;
	display_text = "VIDA = " + std::to_string(player->getVida())  + "  TIEMPO "+ std::to_string((int)actTime);
	if (player->getVida() <= 0) { 
		sm->setFlagPrevious(); 
		if ((int)actTime > *bestTime) *bestTime = (int)actTime;
	}
}

void GameScene::loadScene()
{	
	actTime = 0;
	mEntityManager = new EntityManager(gPh, _gScene);
	leftwind = new windGenerator(Vector3(-105, 9.81, 0), 1);
	timerWind = new WindTimerGenerator(Vector3(-105, 9.81,0), 1,5);
	leftwind->setActive(true);
	timerWind->setActive(true);
	forceslist.push_back(leftwind);
	forceslist.push_back(timerWind);
	player = mEntityManager->createPlayer(Vector3(-20, 10, 0), 5, gPh);
	_gScene->setSimulationEventCallback(player);
	//create the planes
	RigidStatic* a = mEntityManager->createPxPlane();
	player->addToIgnoreList(a->getRigidStatic());
	a = mEntityManager->createPxPlane(Vector3(0,100,0));
	player->addToIgnoreList(a->getRigidStatic());
	

	//Cubes timersystems
	TimerEntitySystem* auxTimeSys = new TimerEntitySystem(mEntityManager,7);
	mEntityManager->addEntity(auxTimeSys);
	pxBoxGausianGenerator* pxBoxgen = new pxBoxGausianGenerator(mEntityManager, Vector3(75, 5, 0), ZERO, Vector3(-15.0,0,0), ZERO, Vector3(10, 20, 30), Vector3(5, 10, 15),
		Vector3(0.8, 0.8, 0.8), Vector3(0.2, 0.1, 0.2), 20, 5, Vector4(0.7, 0.5, 0.8, 1.0), Vector4(0.3, 0.2, 0.4, 0.0), Vector3(4, 4, 2),
		Vector3(3, 2.3, 1.2), 90);
	auxTimeSys->addGenForce(leftwind);
	pxBoxgen->blockZAxesMove();
	auxTimeSys->addGenerator(pxBoxgen);
	auxTimeSys->setActive(true);

	auxTimeSys = new TimerEntitySystem(mEntityManager, 9);
	mEntityManager->addEntity(auxTimeSys);
	pxBoxgen = new pxBoxGausianGenerator(mEntityManager, Vector3(75, 45, 0), ZERO, Vector3(-15.0, 0, 0), ZERO, Vector3(10, 20, 30), Vector3(5, 10, 15),
		Vector3(0.8, 0.8, 0.8), Vector3(0.2, 0.1, 0.2), 30, 5, Vector4(0.1, 0.2, 0.8, 1.0), Vector4(0.3, 0.2, 0.4, 0.0), Vector3(4, 4, 2),
		Vector3(3, 2.3, 1.2), 90);
	auxTimeSys->addGenForce(timerWind);
	pxBoxgen->blockZAxesMove();
	auxTimeSys->addGenerator(pxBoxgen);
	auxTimeSys->setActive(true);

	auxTimeSys = new TimerEntitySystem(mEntityManager, 4);
	mEntityManager->addEntity(auxTimeSys);
	pxBoxgen = new pxBoxGausianGenerator(mEntityManager, Vector3(75, 75, 0), ZERO, Vector3(-15.0, 0, 0), ZERO, Vector3(10, 20, 30), Vector3(5, 10, 15),
		Vector3(0.8, 0.8, 0.8), Vector3(0.2, 0.1, 0.2), 10, 5, Vector4(0.7, 0.8, 0.3, 1.0), Vector4(0.3, 0.2, 0.4, 0.0), Vector3(4, 4, 2),
		Vector3(3, 2.3, 1.2), 90);
	auxTimeSys->addGenForce(leftwind);
	pxBoxgen->blockZAxesMove();
	auxTimeSys->addGenerator(pxBoxgen);
	auxTimeSys->setActive(true);
}



void GameScene::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	player->inputListener(key);
}
