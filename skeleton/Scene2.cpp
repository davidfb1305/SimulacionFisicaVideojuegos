#include "Scene2.h"
#include "GausianGenerator.h"
#include "uniformGenerator.h"
#include "ParticleSystem.h"
Scene2::Scene2(physx::PxPhysics* gPh): SceneTemplate(gPh)
{
	ParticleSystem* ps = new ParticleSystem(mEntityManager);
	//Rain gausian
	//ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	//ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	//ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	//ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1));
	mEntityManager->addEntity(ps);
	//Fog distribucion uniforme 
	//ps->addGenerator(new uniformGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 300.1, 300.1), Vector3(1.1, 1.1, 1.1), Vector3(1.1, 1.1, 1.1), Vector3(0.0, 0.0, 0.0), Vector3(0, 0, 0), Vector4(1.0, 1.0, 1.0,0.5), Vector4(0, 0, 0.0, 0.1), 3));
	//explosion
	//ps->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(1.1, 1.1, 1.1), Vector3(1.1, 1.1, 1.1), Vector3(0.0, 0.0, 0.0), Vector3(100, 100, 100), Vector4(0.5, 0, 0.0, 1), Vector4(0.2, 0, 0.0, 0), 3,0));

}

Scene2::~Scene2()
{
}

void Scene2::loadScene()
{
	rain = new ParticleSystem(mEntityManager);
	//Rain gausian
	rain->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1,100));
	rain->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1,80));
	rain->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1,100));
	rain->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1), Vector3(0.1, -22.0, 0.1), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, -0.5, 0.0), Vector3(0.0, 0.0, 0.0),Vector3(0,0,0),Vector4(0.0,0.0,1.0,1.0),Vector4(0,0,0.5,0), 1,80));
	mEntityManager->addEntity(rain);
	
	//explosion
	explosion = new ParticleSystem(mEntityManager);
	explosion->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 0.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(1.1, 1.1, 1.1), Vector3(1.0, 1.0, 1.0), 1,Vector3(1.1, 1.1, 1.1), Vector3(0.0, 0.0, 0.0), Vector3(100, 100, 100), Vector4(0.5, 0, 0.0, 1), Vector4(0.2, 0, 0.0, 0), 3,100));
	mEntityManager->addEntity(explosion);
	//Fog distribucion uniforme 
	fog = new ParticleSystem(mEntityManager);
	fog->addGenerator(new uniformGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 300.1, 300.1), Vector3(1.1, 1.1, 1.1), Vector3(1.0, 1.0, 1.0), 1, Vector3(1.1, 1.1, 1.1), Vector3(0.0, 0.0, 0.0), Vector3(0, 0, 0), Vector4(1.0, 1.0, 1.0,0.5), Vector4(0, 0, 0.0, 0.1), 3,90));
	mEntityManager->addEntity(fog);
	explosion->setActive(false);
	rain->setActive(false);
	fog->setActive(false);
}

void Scene2::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'E':
		explosion->setActive(!explosion->isActive());
		break;
	case 'R':
		rain->setActive(!rain->isActive());
		break;
	case 'F':
		fog->setActive(!fog->isActive());
		break;
	}
}
