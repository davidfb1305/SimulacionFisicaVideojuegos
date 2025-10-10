#include "Particle.h"
#include <math.h>
Particle::Particle()
{
	vel = Vector3(0, 0, 0);
	ac = Vector3(0, 0, 0);
	dumping = 1;
	mMt = SemiEuler;
}

Particle::Particle( const Vector3& v, const Vector3& a, double d,int mt)
{
	vel = v;
	ac = a; 
	dumping = d;
	mMt = MoveType(mt);
	
}

void Particle::setLastPos(Vector3 a)
{
	lastpos = a;
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
	default:
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
	integrate(t);

	return uptadeDestroyCondition(t);
}
