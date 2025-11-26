#pragma once
#include "Entity.h"
class RigidDynamic : public Entity
{
private:
protected:
	physx::PxRigidDynamic* _mRigid;
	friend class EntityManager;
public:
	RigidDynamic();
	~RigidDynamic();
	physx::PxRigidDynamic* getPxRigidDynamic();
	bool updateDestroyCondition(double t) override;
	virtual bool update(double t) override;
};

