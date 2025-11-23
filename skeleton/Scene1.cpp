#include "Scene1.h"

Scene1::Scene1(physx::PxPhysics* gPh, physx::PxScene* gScene) : SceneTemplate(gPh,gScene)
{

}
Scene1::~Scene1()
{

}

void Scene1::loadScene()
{
	mEntityManager = new EntityManager(gPh,_gScene);
	mEntityManager->createAxes();
	mEntityManager->createParticle(Vector3(0, 0, 0), Vector3(3, 0, 0), Vector3(0, 0, 0), 1, 0);
}

void Scene1::inputListener(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'B': {
		;
		mEntityManager->createBullet(camera.p, GetCamera()->getDir()*10.0,Vector3(0.0,0.0,0.0),0.999,0,2.0,1,10,Vector3(0,0,0),
		Vector4(1.0f,0.0f,1.0f,1.0f),1,1,1,Vector3(500.0,0.0,0.0),1.0, Vector3(0.0,-9.81,0.0));
		break;
	}
	case 'V': {
		;
		mEntityManager->createBullet(camera.p, GetCamera()->getDir() * 50.0, Vector3(0.0, 0.0, 0.0), 0.999, 0, 1.0, 1, 10, Vector3(0, 0, 0),
		Vector4(1.0f, 1.0f, 0.0f, 1.0f), 1, 1, 1, Vector3(500.0, 0.0, 0.0), 1.0, Vector3(0.0, -9.81, 0.0));
		break;
	}
			//case ' ':	break;
	case ' ':
	{
		break;
	}
	default:
		break;
	}
}

