#pragma once
#include "Entity.h"
class RigidStatic : public Entity
{
private:
	physx::PxVec3 vel;
	physx::PxVec3 ac;
	double dumping;
	double massReal = 0.0;
protected:
	physx::PxRigidStatic* _mRigid;
public:
	RigidStatic();
	~RigidStatic();
	bool uptadeDestroyCondition(double t);
	virtual bool update(double t) override;
};

