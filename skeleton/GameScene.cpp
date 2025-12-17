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
GameScene::GameScene(physx::PxPhysics* gPh,physx::PxScene* gScene) :SceneTemplate(gPh,gScene)
{
	
}

GameScene::~GameScene()
{
}

void GameScene::update(double t)
{
	mEntityManager->updateEntities(t);
	///TODO LIMITAR LA SUBIDA DEL JETPACK POR DEBAJO Y POR ARRIBA
	timerWind->updateWindForce(t);
}

void GameScene::loadScene()
{	
	mEntityManager = new EntityManager(gPh, _gScene);
	g = new GravityForceGen();
	leftwind = new windGenerator(Vector3(-105,9.81,0),1);
	timerWind = new WindTimerGenerator(Vector3(-105, 9.81,0), 1,5);
	leftwind->setActive(true);
	timerWind->setActive(true);
	forceslist.push_back(leftwind);
	forceslist.push_back(timerWind);
	player = mEntityManager->createPlayer(Vector3(-20, 10, 0), 5, gPh);
	_gScene->setSimulationEventCallback(player);
	player->addForceGenerator(g);
	forceslist.push_back(g);
	player->addForceGenerator(timerWind);
	player->addForceGenerator(leftwind);
	player->setForceToParticleSystem(forceslist);
	//create the planes
	RigidStatic* a = mEntityManager->createPxPlane();
	player->addToIgnoreList(a->getRigidStatic());
	a = mEntityManager->createPxPlane(Vector3(0,100,0));
	player->addToIgnoreList(a->getRigidStatic());
	//Rain gausian
	rain = new EntitySystem(mEntityManager);

	/*rain->addGenerator(new particleUniformGenerator(mEntityManager, Vector3(0.0, 100.0, 0.0), Vector3(300.1, 0.1, 300.1),
		Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0, 0, 0), Vector4(0.0, 0.0, 1.0, 1.0), Vector4(0, 0, 0.5, 0), 1, 100));
	mEntityManager->addEntity(rain);*/
	rain->addGenForce(g);
	rain->addGenForce(leftwind);
	rain->addGenForce(timerWind);
	rain->setActive(true);

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
	case 'G': 
		g->setActive(!g->isActive());
		break;
	case 'L': 
		leftwind->setActive(!leftwind->isActive());
		break;
	case 'R': 
		timerWind->setActive(!timerWind->isActive());
		break;
	}
}
