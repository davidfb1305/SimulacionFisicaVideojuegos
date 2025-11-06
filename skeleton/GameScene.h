#pragma once
#include "SceneTemplate.h"
#include <list>
class ParticleSystem;
class PlayerEntity;
class GravityForceGen;
class windGenerator;
class GameScene : public SceneTemplate
{
private:
	bool windDir = false; 
	PlayerEntity* player;
	GravityForceGen* g;
	windGenerator* leftwind;
	windGenerator* rightwind;
	ParticleSystem* rain;
	std::list<ForceGenerator*> forceslist;
protected:
public:
	GameScene(physx::PxPhysics* gPh);
	~GameScene();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;

};

