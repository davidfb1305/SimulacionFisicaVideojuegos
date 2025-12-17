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
	jetPackForce = new ForceGenerator(Vector3(0,400,0));
	jetPackForce->setActive(false);
	lastpos = initPos;
	_jetPackPS = new EntitySystem(em);
	jetpack = (Particle*)em->createMassParticle(initPos+Vector3(-10.0, 0.0, 0.0), Vector3(0, 0, 0), Vector3(0, 0, 0), 20);
	
	
	_jetPackPS->addGenerator(new ParticleGausianGenerator(em, initPos+Vector3(-10.0, 0.0, 0.0), Vector3(0.1, 0.1, 0.1), Vector3(1.1, -1.1, 1.1), Vector3(1.0, -1.0, 1.0), 10, Vector3(1.1, -1.1, 1.1)
		, Vector3(0.0, -20.0, 0.0), Vector3(50, 0, 50), Vector4(0.9, 0, 0.0, 1), Vector4(0.1, 0, 0.0, 0), 1, 100,2));
	em->addEntity(_jetPackPS);
	SpringForceGenerator* spring = new SpringForceGenerator(jetpack,700.0,1);
	addForceGenerator(spring);
	jetPackForceForParticles = new ForceGenerator(Vector3(0, -50, 0));
	gravityForMyParticle = new GravityForceGen();
	_jetPackPS->addGenForce(jetPackForceForParticles);
	_jetPackPS->addGenForce(gravityForMyParticle);

	jetpack->addForceGenerator(jetPackForce);
	_jetPackPS->addGenForce(gravityForMyParticle);
	itemsToIgnore = std::list<physx::PxRigidActor*>();
	opositeSpring = (Particle*)em->createMassParticle(initPos+Vector3(10.0, 0.0, 0.0), Vector3(0, 0, 0), Vector3(0, 0, 0), 20);

	spring = new SpringForceGenerator(opositeSpring, 700.0, 1);
	opositeSpring->addForceGenerator(jetPackForce);
	opositeSpring->addForceGenerator(gravityForMyParticle);
	jetpack->addForceGenerator(gravityForMyParticle);
	addForceGenerator(spring);

	
}

PlayerEntity::~PlayerEntity()
{
	this->_mRigid->getScene()->setSimulationEventCallback(nullptr);
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
	// Display text
	std::string vidatext =  "VIDA = \d",vida;
	drawText(vidatext, 10, 0);
	
	addForces();
	_jetPackPS->updatePos(jetpack->mtrans->p);
	_mRigid->addForce(forceToAdd * pow(mass, -1));
	if (jetpack->mtrans->p.y > 95 ) {
		jetpack->setVel(Vector3(0.0, 0.0, 0.0));
		jetpack->mtrans->p.y = 95;
		opositeSpring->setVel(Vector3(0.0, 0.0, 0.0));
		opositeSpring->mtrans->p.y = 95;
		
	}
	else if (jetpack->mtrans->p.y < 5) {
		jetpack->setVel(Vector3(0.0, 0.0, 0.0));
		jetpack->mtrans->p.y = 5;
		opositeSpring->setVel(Vector3(0.0, 0.0, 0.0));
		opositeSpring->mtrans->p.y =5;
	}
	return true;
}

void PlayerEntity::onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs)
{
	physx::PxRigidActor* actor1 = pairHeader.actors[1];
	for (physx::PxRigidActor* a : itemsToIgnore) {
		if ( a == actor1) return;
	}
	vida--;
	
}



void PlayerEntity::setForceToParticleSystem(const std::list<ForceGenerator*>& fg)
{
	for(auto a : fg) _jetPackPS->addForceGenerator(a);
}

void PlayerEntity::addToIgnoreList(physx::PxRigidActor* a)
{
	itemsToIgnore.push_back(a);
}

void PlayerEntity::onConstraintBreak(physx::PxConstraintInfo* constraints, physx::PxU32 count)
{
}

void PlayerEntity::onWake(physx::PxActor** actors, physx::PxU32 count)
{
}

void PlayerEntity::onSleep(physx::PxActor** actors, physx::PxU32 count)
{
}

void PlayerEntity::onTrigger(physx::PxTriggerPair* pairs, physx::PxU32 count)
{
}

void PlayerEntity::onAdvance(const  physx::PxRigidBody* const* bodyBuffer, const  physx::PxTransform* poseBuffer, const  physx::PxU32 count)
{
}
