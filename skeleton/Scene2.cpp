#include "Scene2.h"
#include "GausianGenerator.h"
#include "ParticleSystem.h"
Scene2::Scene2(physx::PxPhysics* gPh): SceneTemplate(gPh)
{
	ParticleSystem* ps = new ParticleSystem(mEntityManager);
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(10.1, 10.1, 0.1), Vector3(1.0, -5.0, 1.0), Vector3(100.1, 100.1, 100.1), Vector3(10.0, 30.1, 24.0),Vector3(10,5,5),Vector4(1.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(10.1, -10.1, 2.1), Vector3(-0.1, 1.0, -1.0), Vector3(-100.1, 100.1, 100.1), Vector3(2.0, 1.0, 20.0), Vector3(10, 5, 5), Vector4(1.0, 0.0, 1.0, 1.0), Vector4(0.1, 0.5, 0, 0),1));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(10.1,10.1, 0.1), Vector3(0.1, -8.0, 2.0), Vector3(10.0, 10.1, -10.0), Vector3(20.0, 10.4, 20.0), Vector3(10, 5, 5), Vector4(1.0, 0.0, 1.0, 1.0), Vector4(0, 0, 0.5, 0), 1));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(10.1, -10.1, -2.1), Vector3(-0.1, 2.0, -2.0), Vector3(-10.0, -10.1, 10.1), Vector3(20.0, 20.2, 30.0), Vector3(10, 5, 5), Vector4(1.0, 0.0, 1.0, 1.0), Vector4(0, 0.5, 0, 0), 1));
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
