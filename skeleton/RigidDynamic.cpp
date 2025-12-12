#include "RigidDynamic.h"
#include "ForceGenerator.h"
void mRigidDynamic::setVolume(float f)
{
	volume = f;
}
void mRigidDynamic::setLinearDamping(float d)
{
	_mRigid->setLinearDamping(d);
}
void mRigidDynamic::setAngularDamping(float d)
{
	_mRigid->setLinearDamping(d);
}
mRigidDynamic::mRigidDynamic(physx::PxScene* mS)
{
    mparentGeneratorList = nullptr;
    mScene = mS;
}

mRigidDynamic::~mRigidDynamic()
{
    mScene->removeActor(*_mRigid);
}

physx::PxRigidDynamic* mRigidDynamic::getPxRigidDynamic()
{
    return _mRigid;
}

bool mRigidDynamic::updateDestroyCondition(double t)
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

Vector3 mRigidDynamic::getLinearVel()
{
	return _mRigid->getLinearVelocity();
}

Vector3 mRigidDynamic::getGlobalPos()
{
	return _mRigid->getGlobalPose().p;
}

bool mRigidDynamic::update(double t)
{
	addForces();
	
	_mRigid->addForce(forceToAdd* pow(mass, -1));
	naturalDestroy = updateDestroyCondition(t);
	return naturalDestroy;
}

void mRigidDynamic::addForces()
{
	forceToAdd = Vector3(0.0, 0.0, 0.0);
	for (auto f : forceList) {
		if (f->checkAddForceEntity(this)) f->addForceToPxEntity(this);
	}
}

float mRigidDynamic::getVolume()
{
	return volume;
}
