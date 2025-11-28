#include "ParticleSystem.h"
#include "ForceGenerator.h"
EntitySystem::EntitySystem(EntityManager* em) : mEntityManager(em)
{
    mItem = nullptr;
    myForceList = std::list<ForceGenerator*>();
}

void EntitySystem::addGenerator(Generator* pg)
{
    generatorList.push_back(pg);
    pg->setmForceList(myForceList);
    
}

void EntitySystem::addGenForce(ForceGenerator* fg)
{
    myForceList.push_back(fg);
    for (auto a : generatorList) a->
        addForceGen(fg);
}

void EntitySystem::remove(ForceGenerator* fg)
{
    myForceList.remove(fg);
}

void EntitySystem::updatePos(Vector3 v)
{
    for (auto a : generatorList) a->updateOriginPos(v);
}



EntitySystem::~EntitySystem()
{
    for (auto a : generatorList) delete a;
}

bool EntitySystem::update(double t)
{
    if (active) {
        for (Generator* pg : generatorList) if (pg->isActive())pg->generate();
    }
    return true;
}
