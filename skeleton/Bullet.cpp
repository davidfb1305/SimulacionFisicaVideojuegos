#include "Bullet.h"

Bullet::Bullet(const physx::PxVec3& p,const physx::PxVec3& v, const physx::PxVec3& vrreal,
	const physx::PxVec3& a, double d, int mt, double m, const physx::PxVec3& g) :
	Particle(p,v,a,d,mt)
{
	massReal = m;
	velReal = vrreal;
	massSim = massReal*(pow((velReal.magnitudeSquared()/vel.magnitudeSquared()),2));
	gSim = g/gDiv;

	acOrg = ac;
	ac = ac + gSim;
}

Bullet::~Bullet()
{
}


