#pragma once
#include "Entity.h"
class ParticleSystem;
class EntityManager; 
class PlayerEntity :public Entity
{
private:
	ParticleSystem* _jetPackPS;
	ForceGenerator* jetPackForce;
	float mass = 10.0;
	float k = 10.0;
protected:

public:
	PlayerEntity(const Vector3 initPos, float size, physx::PxPhysics* gP, EntityManager* em);
	~PlayerEntity();
	void inputListener(unsigned char key);
	bool update(double t) override;
};

