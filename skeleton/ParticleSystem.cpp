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
    for (auto a : generatorList) delete a;
}

bool ParticleSystem::update(double t)
{
    if (active) { 
        for (ParticleGenerator* pg : generatorList) if (pg->isActive())pg->generateParticle(); 
    }
    return true;
}
