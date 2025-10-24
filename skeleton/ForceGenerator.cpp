#include "ForceGenerator.h"

ForceGenerator::ForceGenerator(Vector3 force)
{
    forceToApply = force;
}

bool ForceGenerator::checkAddForce(Entity* p)
{
    return true;
}

bool ForceGenerator::removeForceGenerator(Entity* p)
{
    return false;
}

void ForceGenerator::addForceToParticle(Entity* p)
{
    if (checkAddForce(p)) {
        p->addForce(forceToApply);
    }
}

ForceGenerator::~ForceGenerator()
{
}
