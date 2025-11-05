#include "GameScene.h"
#include "PlayerEntity.h"
GameScene::GameScene(physx::PxPhysics* gPh) :SceneTemplate(gPh)
{
}

GameScene::~GameScene()
{
}

void GameScene::loadScene()
{
	player = mEntityManager->createPlayer(Vector3(0, 0, 0), 5, gPh);
}

void GameScene::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	player->inputListener(key);
}
