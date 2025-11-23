#include "Scene4.h"
#include "Particle.h"
#include "SpringForceGenerator.h"
#include "GravityForceGen.h"
Scene4::Scene4(physx::PxPhysics* gPh, physx::PxScene* gScene)
:SceneTemplate(gPh,gScene){
}

Scene4::~Scene4()
{
}

void Scene4::loadScene()
{   //Cambiar masa de p1 para crear un muelle en un punto fijo; (Para esta prueba se usa Particle pero si el origen no se
	//va a modificar podria ser una entidad pura o cualquier otro tipo de entidad, generador,bullet...)
	mEntityManager = new EntityManager(gPh, _gScene);
	p1 = mEntityManager->createMassParticle(Vector3(0.0, 30.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0.0, 0.0, 0.0), 1.0, Vector3(0.0, 0.0, 0.0), 0.999, 0,1.0,0,0,Vector3(),Vector4(1.0,1.0,1.0,1.0));
	p2 = mEntityManager->createMassParticle(Vector3(10.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
			Vector3(0.0, 0.0, 0.0), 1.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 1.0, 0, 0, Vector3(), Vector4(1.0, 1.0, 1.0, 1.0));
	spring = new SpringForceGenerator(p1, 1.0, 10);
	g = new GravityForceGen();
	p2->addForceGenerator(spring);
	p2->addForceGenerator(g);
	p3 = mEntityManager->createMassParticle(Vector3(20.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0.0, 0.0, 0.0), 2.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 1.0, 0, 0, Vector3(), Vector4(1.0, 1.0, 1.0, 1.0));
	spring1 = new SpringForceGenerator(p2, 1.0, 10);
	spring2 = new SpringForceGenerator(p3, 1.0, 10);
	g = new GravityForceGen();
	p3->addForceGenerator(spring1);
	p2->addForceGenerator(spring2);
	p3->addForceGenerator(g);
	
}

void Scene4::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'G':
		g->setActive(!g->isActive());
		std::cout << "Gravedad = " << g->isActive() << "\n";
		break;
	case 'M':
		spring->setK(spring->getK()+1);
		std::cout << "mas k = " << spring->getK() << "\n";
		break;
	case 'N':
		
		spring->setK(spring->getK() - 1);
		std::cout << "menos k = " << spring->getK() << "\n";
		break;
	}

}
