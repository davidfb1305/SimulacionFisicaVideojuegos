#pragma once
#include "Particle.h"
class Bullet : public Particle
{
private:
	double massReal = 0.0;
	double massSim = 0.0;
	physx::PxVec3  velReal;
	double gDiv = 20.0;
	physx::PxVec3 gSim;
	physx::PxVec3 acOrg;
protected:
	
public:
	Bullet(const physx::PxVec3& p = Vector3(0.0,0.0,0.0),const physx::PxVec3& v = physx::PxVec3(0.0, 0.0, 0.0),const physx::PxVec3& vrreal = physx::PxVec3(0.0, 0.0, 0.0),
		const physx::PxVec3& a = physx::PxVec3(0.0, 0.0, 0.0), double d = 0.999, int mt = 0,double m = 0,const physx::PxVec3& g = Vector3(0.0,0.0,0.0));
	~Bullet();
	
};

