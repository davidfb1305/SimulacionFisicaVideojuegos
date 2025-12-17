#pragma once
#include "RigidDynamic.h"
#include "Particle.h"
class EntitySystem;
class EntityManager; 
class PlayerEntity :public mRigidDynamic, public physx::PxSimulationEventCallback
{
private:
	
protected:
	physx::PxVec3 lastpos;
	EntitySystem* _jetPackPS;
	ForceGenerator* jetPackForce;
	ForceGenerator* jetPackForceForParticles;
	ForceGenerator* gravityForMyParticle;
	float mass = 5.0;
	float k = 1.0;
	friend class EntityManager;
	Particle* jetpack;
	Particle* opositeSpring;
	std::list<physx::PxRigidActor*> itemsToIgnore;
	int vida = 50;
public:
	PlayerEntity(physx::PxScene* mS, const Vector3 initPos, physx::PxPhysics* gP, EntityManager* em);
	~PlayerEntity();
	void inputListener(unsigned char key);
	bool update(double d) override;
	void setForceToParticleSystem(const std::list<ForceGenerator*>& fg);
	void addToIgnoreList(physx::PxRigidActor* a);
	int getVida();
	// Heredado vía PxSimulationEventCallback
	void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs) override;
	void onWake(physx::PxActor** actors, physx::PxU32 count) override;
	void onSleep(physx::PxActor** actors, physx::PxU32 count) override;
	void onTrigger(physx::PxTriggerPair* pairs, physx::PxU32 count) override;
	void onConstraintBreak(physx::PxConstraintInfo* constraints, physx::PxU32 count) override;
	void onAdvance(const  physx::PxRigidBody* const* bodyBuffer, const  physx::PxTransform* poseBuffer, const  physx::PxU32 count) override;
};

