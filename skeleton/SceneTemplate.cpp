#include "SceneTemplate.h"

SceneTemplate::SceneTemplate(physx::PxPhysics* gPh)
{
	mEntityManager = new EntityManager(gPh);
}

SceneTemplate::~SceneTemplate()
{
	delete mEntityManager;
}

void SceneTemplate::loadScene()
{

}

void SceneTemplate::unLoadScene()
{
	mEntityManager->ReleaseEntities();
}

void SceneTemplate::update(double t)
{
	mEntityManager->updateEntities(t);
}
