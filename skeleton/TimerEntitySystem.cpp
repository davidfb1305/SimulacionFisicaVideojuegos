#include "TimerEntitySystem.h"

TimerEntitySystem::TimerEntitySystem(EntityManager* em, float genTime) : EntitySystem(em)
{
    _genTime = genTime;
    _actTime = genTime;
}

TimerEntitySystem::~TimerEntitySystem()
{
}

bool TimerEntitySystem::update(double t)
{
    _actTime -= t;
    if (active&& _actTime<0) {
        for (Generator* pg : generatorList) if (pg->isActive())pg->generate();
        _actTime = _genTime;
    }
    return true;
}
