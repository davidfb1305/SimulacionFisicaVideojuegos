#include "ParticleSystem.h"
#include "ForceGenerator.h"
ParticleSystem::ParticleSystem(EntityManager* em) : mEntityManager(em)
{
    myForceList = std::list<ForceGenerator*>();
}

void ParticleSystem::addGenerator(ParticleGenerator* pg)
{
    generatorList.push_back(pg);
    pg->setmForceList(&myForceList);
    
}

void ParticleSystem::addGenForce(ForceGenerator* fg)
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
