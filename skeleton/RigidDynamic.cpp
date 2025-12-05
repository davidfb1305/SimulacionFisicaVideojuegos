#include "RigidDynamic.h"

RigidDynamic::RigidDynamic(physx::PxScene* mS)
{
    mparentGeneratorList = nullptr;
    mScene = mS;
}

RigidDynamic::~RigidDynamic()
{
    if (mparentGeneratorList != nullptr) mparentGeneratorList->remove(this);
    mScene->removeActor(*_mRigid);
}

physx::PxRigidDynamic* RigidDynamic::getPxRigidDynamic()
{
    return _mRigid;
}

bool RigidDynamic::updateDestroyCondition(double t)
{
	switch (mRc)
	{
	case NONE:
		return true;
		break;
	case TIME:
		timeToRemove -= t;
		return (timeToRemove > 0);
		break;
	case DISTANCE:
		Vector3 auxpos = Vector3(std::abs(mtrans->p.x), std::abs(mtrans->p.y), std::abs(mtrans->p.z));
		return (auxpos.x < maxpos.x && auxpos.y < maxpos.y && auxpos.z < maxpos.z);
		break;
	}
}

bool RigidDynamic::update(double t)
{
	return updateDestroyCondition(t);
}
