#include "GravityForceGen.h"
#include "Particle.h"

GravityForceGen::GravityForceGen() : ForceGenerator(Vector3(0.0,-9.81,0.0))
{
}

GravityForceGen::~GravityForceGen()
{
}

void GravityForceGen::addForceToParticle(Particle* p)
{
    p->addForce(p->getMass()*forceToApply);
}


bool GravityForceGen::checkAddForce(Particle* p)
{
    return _active;
}

bool GravityForceGen::removeForceGenerator(Particle* p)
{
    return false;
}

