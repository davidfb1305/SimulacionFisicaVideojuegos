#include "Particle.h"
#include "ForceGenerator.h"
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
	massSim =  mass;
	
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

bool Particle::updateDestroyCondition(double t)
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
		vel += (t * ac * pow(massSim, -1));
		vel *= pow(dumping, t);
		mtrans->p += (t * vel);
		break;
	case Euler:

		vel += (t * ac * pow(massSim, -1));
		vel *= pow(dumping, t);
		mtrans->p += (t * vel);
		break;
	case Valet:
		Vector3 aux = lastpos;
		lastpos = mtrans->p;
		mtrans->p = (((2 * mtrans->p) - aux) + (pow(t, 2) * ac));
		break;

	}
}
void Particle::addForces()
{
	for (ForceGenerator* f : forceList){
		if(f->checkAddForce(this)) f->addForceToParticle(this);
	}
}
bool Particle::update(double t) 
{
	clearForce();
	addForces();
	ac =  forceToAdd;
	integrate(t);

	return updateDestroyCondition(t);
}
