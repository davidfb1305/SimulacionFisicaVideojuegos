#include "Generator.h"
Generator::Generator(int _max)
{
    _maxEntities = _max;
    entityList = std::list<Entity*>();
}
Generator::~Generator()
{
   
}
bool Generator::isActive()
{
    return active;
}

void Generator::setActive(bool b)
{
    active = b;
}

void Generator::setmForceList(std::list<ForceGenerator*> fl)
{
    forceList = fl;
}

void Generator::addForceGen(ForceGenerator* f)
{
    forceList.push_back(f);
}
void Generator::updateOriginPos(Vector3 v)
{
    pos += v;
}