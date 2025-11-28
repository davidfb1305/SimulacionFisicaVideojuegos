#pragma once
#include "SceneTemplate.h"
#include <list>
class EntitySystem;
class PlayerEntity;
class GravityForceGen;
class windGenerator;
class WindTimerGenerator;
class GameScene : public SceneTemplate
{
private:
	bool windDir = false; 
	PlayerEntity* player;
	GravityForceGen* g;
	windGenerator* leftwind;
	WindTimerGenerator* rightwind;
	EntitySystem* rain;
	std::list<ForceGenerator*> forceslist;
protected:
public:
	GameScene(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~GameScene();
	void update(double t)override;
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;

};

