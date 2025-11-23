#include "RigidStatic.h"


RigidStatic::RigidStatic()
{
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
