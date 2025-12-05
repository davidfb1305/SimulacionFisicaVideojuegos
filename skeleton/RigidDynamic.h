#pragma once
#include "Entity.h"
class RigidDynamic : public Entity
{
private:
protected:
	physx::PxRigidDynamic* _mRigid;
	friend class EntityManager;
	physx::PxScene* mScene;
public:
	RigidDynamic(physx::PxScene* mS);
	~RigidDynamic();
	physx::PxRigidDynamic* getPxRigidDynamic();
	bool updateDestroyCondition(double t) override;
	virtual bool update(double t) override;
	void addForces() override;
};

