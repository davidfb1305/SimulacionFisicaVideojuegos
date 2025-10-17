#include "Scene2.h"
#include "GausianGenerator.h"
#include "ParticleSystem.h"
Scene2::Scene2(physx::PxPhysics* gPh): SceneTemplate(gPh)
{
	ParticleSystem* ps = new ParticleSystem(mEntityManager);
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(1.1, 0.1, 1.1), Vector3(0.0, 5.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(0.0, 0.1, 0.0), 2));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(0.1, 0.1, 2.1), Vector3(0.1, 1.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(0.0, 0.0, 0.0), 2));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(0.1, 8.0, 0.0), Vector3(0.0, 0.1, 0.0), Vector3(0.0, 0.0, 0.0), 2));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(1.1, 0.1, 1.1), Vector3(0.1, 2.0, 0.0), Vector3(0.0, 0.1, 0.1), Vector3(0.0, 0.0, 0.0), 2));
	mEntityManager->addEntity(ps);
}

Scene2::~Scene2()
{
}

void Scene2::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'E':
		for (auto e : mEntityManager->getEntityList()) e->setActive(!e->isActive());
		break;
	default:
		break;
	}
}
