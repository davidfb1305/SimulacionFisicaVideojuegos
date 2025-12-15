#include "PlayerEntity.h"
#include "EntitySystem.h"
#include "GausianGenerator.h"
#include "SpringForceGenerator.h"
#include "ForceGenerator.h"
#include "EntityManager.h"
#include "GravityForceGen.h"
PlayerEntity::PlayerEntity(physx::PxScene* mS,const Vector3 initPos, physx::PxPhysics* gP, EntityManager* em)
	:mRigidDynamic(mS)
{
	jetPackForce = new ForceGenerator(Vector3(0,300,0));
	jetPackForce->setActive(false);
	lastpos = initPos;
	_jetPackPS = new EntitySystem(em);
	jetpack = (Particle*)em->createMassParticle(Vector3(-10.0, 0.0, 0.0), Vector3(0, 0, 0), Vector3(0, 0, 0), 10);
	_jetPackPS->addGenerator(new ParticleGausianGenerator(em, Vector3(-10.0, 0.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(1.1, 1.1, 1.1), Vector3(1.0, 1.0, 1.0), 10, Vector3(1.1, 1.1, 1.1)
		, Vector3(0.0, -20.0, 0.0), Vector3(50, 0, 50), Vector4(1.0, 0, 0.0, 1), Vector4(0.2, 0, 0.0, 0), 1, 100,2));
	em->addEntity(_jetPackPS);
	SpringForceGenerator* spring = new SpringForceGenerator(jetpack,400.0,1);
	addForceGenerator(spring);
	jetPackForceForParticles = new ForceGenerator(Vector3(0, -50, 0));
	_jetPackPS->addForceGenerator(jetPackForceForParticles);
	gravityForMyParticle = new GravityForceGen();
	jetpack->addForceGenerator(jetPackForce);

	opositeSpring = (Particle*)em->createMassParticle(Vector3(10.0, 0.0, 0.0), Vector3(0, 0, 0), Vector3(0, 0, 0), 10);

	spring = new SpringForceGenerator(opositeSpring, 400.0, 1);
	opositeSpring->addForceGenerator(jetPackForce);
	opositeSpring->addForceGenerator(gravityForMyParticle);
	jetpack->addForceGenerator(gravityForMyParticle);
	addForceGenerator(spring);
	
}

PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::inputListener(unsigned char key)
{
	switch (toupper(key))
	{
	case 'Z': {
		_jetPackPS->setActive(!_jetPackPS->isActive());
		jetPackForce->setActive(!jetPackForce->isActive());
		break;
		}
	}
}

bool PlayerEntity::update(double d)
{
	addForces();
	_jetPackPS->updatePos(jetpack->mtrans->p);
	_mRigid->addForce(forceToAdd * pow(mass, -1));
	if (jetpack->mtrans->p.y > 95 || jetpack->mtrans->p.y < 5) {
		jetpack->setVel(Vector3(0.0, 0.0, 0.0));
		jetpack->mtrans->p.y = _mRigid->getGlobalPose().p.y;
		opositeSpring->setVel(Vector3(0.0, 0.0, 0.0));
		opositeSpring->mtrans->p.y = _mRigid->getGlobalPose().p.y;
		
	}
	return true;
}



void PlayerEntity::setForceToParticleSystem(const std::list<ForceGenerator*>& fg)
{
	for(auto a : fg) _jetPackPS->addForceGenerator(a);
}
