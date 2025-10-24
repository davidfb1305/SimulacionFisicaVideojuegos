#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(EntityManager* em) : mEntityManager(em)
{
}

void ParticleSystem::addGenerator(ParticleGenerator* pg)
{   
    pg->setForceList(&myForceList);
    generatorList.push_back(pg);
}

void ParticleSystem::addForce(ForceGenerator* fg)
{
    myForceList.push_back(fg);
}

void ParticleSystem::remove(ForceGenerator* fg)
{
    myForceList.remove(fg);
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
