#include "Scene3.h"
#include "ParticleSystem.h"
#include "GravityForceGen.h"
#include "GausianGenerator.h"
#include "windGenerator.h"
#include "whirlGenerator.h"
Scene3::Scene3(physx::PxPhysics* gPh, physx::PxScene* gScene) :SceneTemplate(gPh,gScene)
{
	std::cout << "Q activa y desactiva el viento, G la gravedad y T el ciclon\n";

}

Scene3::~Scene3()
{
	delete _windGen;
	delete _gravityGen;
	delete _whirlGen;
}

void Scene3::loadScene()
{
	mEntityManager = new EntityManager(gPh, _gScene);
	prueba = new EntitySystem(mEntityManager);
	//Rain gausian
	prueba->addGenerator(new GausianGenerator(mEntityManager, Vector3(0.0, 30.0, 0.0), Vector3(300.1, 0.1, 300.1),
		Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0, 0, 0), Vector4(0.0, 0.0, 1.0, 1.0), Vector4(0, 0, 0.5, 0), 1, 100));
	mEntityManager->addEntity(prueba);
	prueba->setActive(true);
	_gravityGen = new GravityForceGen();
	prueba->addGenForce(_gravityGen);
	_whirlGen = new whirlGenerator(Vector3(0, 0, 0), 1);
	prueba->addGenForce(_whirlGen);
	_windGen = new windGenerator(Vector3(10, 0, 0), 1);
	prueba->addGenForce(_windGen);
}

void Scene3::inputListener(unsigned char key, const physx::PxTransform& camera)
{

	switch (toupper(key))
	{
	case 'G':
		_gravityGen->setActive(!_gravityGen->isActive());
		break;
	case 'T':
		_whirlGen->setActive(!_whirlGen->isActive());
		break;
	case 'Q':
		_windGen->setActive(!_windGen->isActive());
		break;
	}
}
