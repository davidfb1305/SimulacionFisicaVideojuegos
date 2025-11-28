#pragma once
#include "Entity.h"
class EntitySystem;
class EntityManager; 
class PlayerEntity :public Entity
{
private:
	physx::PxVec3 vel;
	physx::PxVec3 ac;
	double dumping = 0.999;
	physx::PxVec3 lastpos;
	EntitySystem* _jetPackPS;
	ForceGenerator* jetPackForce;
	ForceGenerator* jetPackForceForParticles;
	float mass = 1.0;
	float k = 0.0;
protected:

public:
	PlayerEntity(const Vector3 initPos, physx::PxPhysics* gP, EntityManager* em);
	~PlayerEntity();
	void inputListener(unsigned char key);
	void integrate(double t);
	void addForces() override;
	bool update(double t) override;
	inline Vector3 getVel() { return vel; };
	inline float getK() { return k; };
	void setForceToParticleSystem(const std::list<ForceGenerator*>& fg);
};

