#include "Scene2.h"
#include "GausianGenerator.h"
#include "ParticleSystem.h"
Scene2::Scene2(physx::PxPhysics* gPh): SceneTemplate(gPh)
{
	ParticleSystem* ps = new ParticleSystem(mEntityManager);
	//Rain gausian
	/*ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	*/mEntityManager->addEntity(ps);
	//Fog distribucion uniforme WIP
	//ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 300.1, 300.1), Vector3(1.1, 1.1, 1.1), Vector3(1.1, 1.1, 1.1), Vector3(0.0, 0.0, 0.0), Vector3(0, 0, 0), Vector4(1.0, 1.0, 1.0,0.5), Vector4(0, 0, 0.0, 0.1), 3));
	//explosion
	ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(1.1, 1.1, 1.1), Vector3(1.1, 1.1, 1.1), Vector3(0.0, 0.0, 0.0), Vector3(100, 100, 100), Vector4(0.5, 0, 0.0, 1), Vector4(0.2, 0, 0.0, 0), 3));

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
