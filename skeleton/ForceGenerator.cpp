#include "ForceGenerator.h"
#include "PlayerEntity.h"
#include "Particle.h"
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
        p->addForce(forceToApply);
}

bool ForceGenerator::checkAddForceEntity(Entity* p)
{
    return _active;
}

void ForceGenerator::addForceToEntity(PlayerEntity* p)
{
    p->addForce(forceToApply);
}

void ForceGenerator::setActive(bool b)
{
    _active = b;
}
ForceGenerator::~ForceGenerator()
{
}
