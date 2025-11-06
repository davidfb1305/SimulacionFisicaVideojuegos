#include "GameScene.h"
#include "PlayerEntity.h"
#include "GravityForceGen.h"
#include "particleSystem.h"
#include "GausianGenerator.h"
#include "uniformGenerator.h"
#include "windGenerator.h"
GameScene::GameScene(physx::PxPhysics* gPh) :SceneTemplate(gPh)
{
}

GameScene::~GameScene()
{
}

void GameScene::loadScene()
{
	
	g = new GravityForceGen();
	leftwind = new windGenerator(Vector3(-5,0,0),1);
	rightwind = new windGenerator(Vector3(5, 0, 0), 1);
	leftwind->setActive(false);
	rightwind->setActive(false);
	forceslist.push_back(leftwind);
	forceslist.push_back(rightwind);
	player = mEntityManager->createPlayer(Vector3(0, 0, 0), 5, gPh);
	player->addForceGenerator(g);
	forceslist.push_back(g);
	player->addForceGenerator(rightwind);
	player->addForceGenerator(leftwind);
	player->setForceToParticleSystem(forceslist);
	//Rain gausian
	rain = new ParticleSystem(mEntityManager);

	rain->addGenerator(new uniformGenerator(mEntityManager, Vector3(0.0, 100.0, 0.0), Vector3(300.1, 0.1, 300.1),
		Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0, 0, 0), Vector4(0.0, 0.0, 1.0, 1.0), Vector4(0, 0, 0.5, 0), 1, 100));
	mEntityManager->addEntity(rain);
	rain->addGenForce(g);
	rain->addGenForce(leftwind);
	rain->addGenForce(rightwind);
	rain->setActive(true);
}



void GameScene::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	player->inputListener(key);
	switch (toupper(key))
	{
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
		rightwind->setActive(!rightwind->isActive());
		break;
	}
}
