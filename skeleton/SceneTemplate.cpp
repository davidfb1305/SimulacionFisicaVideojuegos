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
	for (auto e : mEntityManager->getEntityList()) e->setActive(true);
}

void SceneTemplate::unLoadScene()
{
	for (auto e : mEntityManager->getEntityList()) e->setActive(false);
}
void SceneTemplate::inputListener(unsigned char key, const physx::PxTransform& camera) {

 }

void SceneTemplate::update(double t)
{
	mEntityManager->updateEntities(t);
}
