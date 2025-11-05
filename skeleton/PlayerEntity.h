#pragma once
#include "Entity.h"
class ParticleSystem;
class EntityManager; 
class PlayerEntity :public Entity
{
private:
	physx::PxVec3 vel;
	physx::PxVec3 ac;
	double dumping = 0.999;
	physx::PxVec3 lastpos;
	ParticleSystem* _jetPackPS;
	ForceGenerator* jetPackForce;
	ForceGenerator* jetPackForceForParticles;
	float mass = 10.0;
	float k = 10.0;
protected:

public:
	PlayerEntity(const Vector3 initPos, physx::PxPhysics* gP, EntityManager* em);
	~PlayerEntity();
	void inputListener(unsigned char key);
	void integrate(double t);
	void addForces() override;
	bool update(double t) override;
};

