#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(EntityManager* em) : mEntityManager(em)
{
}

void ParticleSystem::addGenerator(ParticleGenerator* pg)
{
    generatorList.push_back(pg);
}

ParticleSystem::~ParticleSystem()
{
}

bool ParticleSystem::update(double t)
{
    for (ParticleGenerator* pg : generatorList) if(pg->isActive())pg->generateParticle();
    return true;
}
