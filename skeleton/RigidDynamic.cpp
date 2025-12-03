#include "RigidDynamic.h"

RigidDynamic::RigidDynamic(physx::PxScene* mS)
{
    mScene = mS;
}

RigidDynamic::~RigidDynamic()
{
    mScene->removeActor(*_mRigid);
}

physx::PxRigidDynamic* RigidDynamic::getPxRigidDynamic()
{
    return nullptr;
}

bool RigidDynamic::updateDestroyCondition(double t)
{
    return false;
}

bool RigidDynamic::update(double t)
{
    return true;
}
