#pragma once
#include "SceneTemplate.h"
class ParticleSystem;
class PlayerEntity;
class GameScene : public SceneTemplate
{
private:
	PlayerEntity* player;
	ParticleSystem* rain;
protected:
public:
	GameScene(physx::PxPhysics* gPh);
	~GameScene();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;

};

