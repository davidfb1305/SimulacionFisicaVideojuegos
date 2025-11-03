#include "ForceGenerator.h"

ForceGenerator::ForceGenerator(Vector3 force)
{
    forceToApply = force;
}

bool ForceGenerator::checkAddForce(Particle* p)
{
    return true;
}

bool ForceGenerator::removeForceGenerator(Particle* p)
{
    return false;
}

void ForceGenerator::addForceToParticle(Particle* p)
{
    if (checkAddForce(p)) {
        p->addForce(forceToApply);
    }
}

ForceGenerator::~ForceGenerator()
{
}
