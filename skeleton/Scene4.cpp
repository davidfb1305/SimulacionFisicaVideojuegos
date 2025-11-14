#include "Scene4.h"
#include "Particle.h"
#include "SpringForceGenerator.h"
#include "GravityForceGen.h"
Scene4::Scene4(physx::PxPhysics* gPh)
:SceneTemplate(gPh){
}

Scene4::~Scene4()
{
}

void Scene4::loadScene()
{   //Cambiar masa de p1 para crear un muelle en un punto fijo; (Para esta prueba se usa Particle pero si el origen no se
	//va a modificar podria ser una entidad pura o cualquier otro tipo de entidad, generador,bullet...)
	Entity* p1 = mEntityManager->createMassParticle(Vector3(0.0,0.0,0.0), Vector3(0.0, 0.0, 0.0), 
		Vector3(0.0, 0.0, 0.0), 0.0, Vector3(0.0, 0.0, 0.0), 0.999, 0,1.0);
	Entity* p2 = mEntityManager->createMassParticle(Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
			Vector3(0.0, 0.0, 0.0), 5.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 1.0);
	SpringForceGenerator* spring = new SpringForceGenerator(p1, 1.0, 10);
	GravityForceGen* g = new GravityForceGen();
	p2->addForceGenerator(spring);
	p2->addForceGenerator(g);
}

void Scene4::inputListener(unsigned char key, const physx::PxTransform& camera)
{
}
