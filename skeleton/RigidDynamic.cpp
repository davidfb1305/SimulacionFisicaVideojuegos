#include "RigidDynamic.h"

RigidDynamic::RigidDynamic()
{

}

RigidDynamic::~RigidDynamic()
{
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
