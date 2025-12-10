#include "SpringForceGenerator.h"
#include "RigidDynamic.h"
#include "Particle.h"

SpringForceGenerator::SpringForceGenerator(Entity* ori, double k, double resting_length)
: ForceGenerator(Vector3(0.0,0.0,0.0)){
	_ori = ori;
	_k = k;
	_resting_length = resting_length;
}

SpringForceGenerator::~SpringForceGenerator()
{
}

void SpringForceGenerator::addForceToParticle(Particle* p)
{
	Vector3 relativePos = _ori->mtrans->p - p->mtrans->p;
	float length = relativePos.normalize();
	float deltaX = length - _resting_length;
	forceToApply = relativePos * deltaX * _k;
	p->addForce(forceToApply);
}

void SpringForceGenerator::addForceToPxEntity(RigidDynamic* p)
{
	Vector3 relativePos = _ori->mtrans->p - p->mtrans->p;
	float length = relativePos.normalize();
	float deltaX = length - _resting_length;
	forceToApply = relativePos * deltaX * _k;
	p->addForce(forceToApply);
}

