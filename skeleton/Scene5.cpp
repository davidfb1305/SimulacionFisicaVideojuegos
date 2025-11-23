#include "Scene5.h"
#include "BuoyancyForceGenerator.h"
#include "GravityForceGen.h"
#include "Particle.h"
Scene5::Scene5(physx::PxPhysics* gPh, physx::PxScene* gScene):
SceneTemplate(gPh,gScene){
}

Scene5::~Scene5()
{
}

void Scene5::loadScene()
{
	mEntityManager = new EntityManager(gPh, _gScene);
	//body
	Entity* p = mEntityManager->createMassParticle(Vector3(0.0, 10.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0.0, 0.0, 0.0), 100.0, Vector3(0.0, 0.0, 0.0), 0.5, 0, 1.0, 0, 0, Vector3(), Vector4(1.0, 1.0, 1.0, 1.0));
	//water 
	Entity* plane = mEntityManager->createPlane(Vector3(1, 1, 1), Vector3(10, 0.001, 10),Vector4(0.0,0.0,1.0,1.0));
	//forceGenerators
	GravityForceGen* g = new GravityForceGen();
	BuoyancyForceGenerator* aux = new BuoyancyForceGenerator(plane,10,1,1000,9.8);
	p->addForceGenerator(g);
	p->addForceGenerator(aux);
}
