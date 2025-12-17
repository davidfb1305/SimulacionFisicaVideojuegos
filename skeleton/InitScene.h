#pragma once
#include "SceneTemplate.h"
class SceneManager;
class PlayerEntity;

class InitScene : public SceneTemplate
{
private:
	int* bestTime;
	SceneManager* sm;
	PlayerEntity* player;
protected:
public:
	
	InitScene(physx::PxPhysics* gPh, physx::PxScene* gScene, SceneManager* sManager, int* bt);
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
	~InitScene();
};

