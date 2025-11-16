#include "Scene5.h"
#include "BuoyancyForceGenerator.h"
#include "GravityForceGen.h"
#include "Particle.h"
Scene5::Scene5(physx::PxPhysics* gPh):
SceneTemplate(gPh){
}

Scene5::~Scene5()
{
}

void Scene5::loadScene()
{
	mEntityManager = new EntityManager(gPh);
	//body
	Entity* p = mEntityManager->createMassParticle(Vector3(0.0, 10.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0.0, 0.0, 0.0), 1.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 1.0, 0, 0, Vector3(), Vector4(1.0, 1.0, 1.0, 1.0));
	//water 
	Entity* plane = mEntityManager->createPlane(Vector3(1, 1, 1), Vector3(10, 0.001, 10),Vector4(0.0,0.0,1.0,1.0));
	//forceGenerators
	GravityForceGen* g = new GravityForceGen();
	BuoyancyForceGenerator* aux = new BuoyancyForceGenerator(plane,10,10,0.05,9.8);
	p->addForceGenerator(g);
	p->addForceGenerator(aux);
}
