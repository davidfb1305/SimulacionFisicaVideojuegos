#include "ForceGenerator.h"

ForceGenerator::ForceGenerator(Vector3 force)
{
    forceToApply = force;
}

bool ForceGenerator::checkAddForce(Particle* p)
{

    return _active;
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
void ForceGenerator::setActive(bool b)
{
    _active = b;
}
ForceGenerator::~ForceGenerator()
{
}
