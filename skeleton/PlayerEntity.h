#pragma once
#include "RigidDynamic.h"
#include "Particle.h"
class EntitySystem;
class EntityManager; 
class PlayerEntity :public mRigidDynamic
{
private:
	
protected:
	physx::PxVec3 lastpos;
	EntitySystem* _jetPackPS;
	ForceGenerator* jetPackForce;
	ForceGenerator* jetPackForceForParticles;
	ForceGenerator* gravityForMyParticle;
	float mass = 1.0;
	float k = 1.0;
	friend class EntityManager;
	Particle* jetpack;
	Particle* opositeSpring;
public:
	PlayerEntity(physx::PxScene* mS, const Vector3 initPos, physx::PxPhysics* gP, EntityManager* em);
	~PlayerEntity();
	void inputListener(unsigned char key);
	bool update(double d) override;
	void setForceToParticleSystem(const std::list<ForceGenerator*>& fg);
};

