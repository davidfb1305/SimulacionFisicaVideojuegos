#include "Particle.h"
#include <math.h>
/*
Particle::Particle(const Vector3& p, const Vector3& v, const Vector3& a, double d,int mt, int rc, int rct, Vector3 maxdis)
{
	vel = v;
	ac = a; 
	dumping = d;
	mMt = MoveType(mt);
	mRc = RemoveCondition(rc);
	timeToRemove = rct;
	maxdistance = maxdis;
	initpos = p;
	maxpos = p + maxdis;

	massReal = 1;
	velReal = Vector3(1.0,1.0,1.0);
	massSim = massReal;// *(pow((velReal.magnitudeSquared() / vel.magnitudeSquared()), 2));
}

*/

Particle::Particle(const Vector3& p, const Vector3& v,
	const Vector3& a, double d, int mt, int rc, int rct, Vector3 maxdis, Vector3& vr, double mass)
{
	vel = v;
	ac = a;
	dumping = d;
	mMt = MoveType(mt);
	mRc = RemoveCondition(rc);
	timeToRemove = rct;
	maxdistance = maxdis;
	initpos = p;
	maxpos = p + maxdis;

	
	velReal = vr;
	massReal = mass;
	massSim = massReal;
	
}

void Particle::setLastPos(Vector3 a)

{
	lastpos = a;
}

void Particle::setMass(double d)
{
	massReal = d;
	massSim = d;
}

bool Particle::uptadeDestroyCondition(double t)
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
		return (auxpos.x < maxpos.x&& auxpos.y < maxpos.y&& auxpos.z < maxpos.z);
		break;
	}
	
}


Particle::~Particle()
{
}



void Particle::integrate(double t)
{
	switch (mMt)
	{
	case SemiEuler:
		vel += (t * ac);
		mtrans->p += (t * vel);
		break;
	case Euler:
		mtrans->p += (t * vel);
		vel += (t * ac);
		vel *= pow(dumping, t);
		break;
	case Valet:
		Vector3 aux = lastpos;
		lastpos = mtrans->p;
		mtrans->p = (((2 * mtrans->p) - aux) + (pow(t, 2) * ac));
		break;

	}
}
bool Particle::update(double t) 
{
	clearForce();
	addForces();
	ac =  forceToAdd* pow(massSim,-1);
	integrate(t);

	return uptadeDestroyCondition(t);
}
