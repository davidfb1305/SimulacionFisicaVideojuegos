#include "ParticleGenerator.h"
#include "ForceGenerator.h"


ParticleGenerator::ParticleGenerator(EntityManager* m, Vector3 p, Vector3 v, Vector3 vr,
    double ms,Vector3 a, double rd, int genprob,std::list<ForceGenerator*> fl)
{
    mEntityManager = m;
    pos = p;
    vel = v;
    velReal = vr;
    mass = ms;
    ac = a;
    r = rd;
    generateProb = genprob;
    forceList = fl;
}

ParticleGenerator::~ParticleGenerator()
{
}

void ParticleGenerator::setPos(Vector3 v)
{
    pos = v;
}

void ParticleGenerator::setVel(Vector3 v)
{
    pos = v;
}

void ParticleGenerator::setac(Vector3 v)
{
    ac = v;
}

void ParticleGenerator::setmForceList(std::list<ForceGenerator*> fl)
{
    forceList = fl;
}

void ParticleGenerator::addForceGen(ForceGenerator* f)
{
    forceList.push_back(f);
}

void ParticleGenerator::setR(double v)
{
    r = v;
}

const Vector3 ParticleGenerator::getPos()
{
    return pos;
}

const Vector3 ParticleGenerator::getVel()
{
    return vel;
}

const Vector3 ParticleGenerator::getAc()
{
    return ac;
}

const double ParticleGenerator::getR()
{
    return r;
}

bool ParticleGenerator::isActive()
{
    return active;
}

void ParticleGenerator::setActive(bool b)
{
    active = b;
}

void ParticleGenerator::updateOriginPos(Vector3 v)
{
    pos + v;
}
