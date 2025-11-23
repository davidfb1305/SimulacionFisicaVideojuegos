#pragma once
#include "EntityManager.h"
#include <PxPhysicsAPI.h>
class SceneTemplate
{
private:
	
protected:
	EntityManager* mEntityManager;
	physx::PxPhysics* gPh;
	physx::PxScene* _gScene;
public:
	SceneTemplate(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~SceneTemplate();
	void unLoadScene();
	virtual void update(double t);
	virtual void loadScene();
	virtual void inputListener(unsigned char key, const physx::PxTransform& camera);
};

