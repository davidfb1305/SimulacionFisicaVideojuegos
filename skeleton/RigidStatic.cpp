#include "RigidStatic.h"


RigidStatic::RigidStatic()
{
	vel = Vector3(0.0, 0.0, 0.0);
	ac = Vector3(0.0, 0.0, 0.0);
	dumping = 0;
}

RigidStatic::~RigidStatic()
{
}

physx::PxRigidStatic* RigidStatic::getRigidStatic()
{
	return _mRigid;
}

bool RigidStatic::updateDestroyCondition(double t)
{
	return false;
}

bool RigidStatic::update(double t)
{
	return true;
}
