#include "SceneTemplate.h"

SceneTemplate::SceneTemplate(physx::PxPhysics* gPh)
{
	mEntityManager = new EntityManager(gPh);
	this->gPh = gPh;
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
	delete mEntityManager;
}
void SceneTemplate::inputListener(unsigned char key, const physx::PxTransform& camera) {

 }

void SceneTemplate::update(double t)
{
	mEntityManager->updateEntities(t);
}
