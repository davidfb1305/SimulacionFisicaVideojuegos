#include "Scene3.h"
#include "ParticleSystem.h"
#include "GravityForceGen.h"
#include "GausianGenerator.h"
#include "windGenerator.h"
Scene3::Scene3(physx::PxPhysics* gPh) :SceneTemplate(gPh)
{
	GravityForceGen* aux = new GravityForceGen();
	prueba = new ParticleSystem(mEntityManager);
	//Rain gausian
	prueba->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1),
		Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0),1, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0, 0, 0), Vector4(0.0, 0.0, 1.0, 1.0), Vector4(0, 0, 0.5, 0), 1, 100));
	mEntityManager->addEntity(prueba);
	prueba->addGenForce(aux);
	windGenerator* aux1 = new windGenerator(Vector3(10,0,0),1);
	prueba->addGenForce(aux1);
	prueba->setActive(true);
}

Scene3::~Scene3()
{
}

void Scene3::loadScene()
{
}

void Scene3::inputListener(unsigned char key, const physx::PxTransform& camera)
{
}
