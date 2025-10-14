#pragma once
#include "EntityManager.h"
class SceneTemplate
{
private:
	
protected:
	EntityManager* mEntityManager;
public:
	SceneTemplate(physx::PxPhysics* gPh);
	~SceneTemplate();
	void unLoadScene();
	void update(double t);
	virtual void loadScene();
};

