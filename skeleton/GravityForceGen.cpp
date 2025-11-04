#include "GravityForceGen.h"

GravityForceGen::GravityForceGen() : ForceGenerator(Vector3(0.0,-9.81,0.0))
{
}

GravityForceGen::~GravityForceGen()
{
}

bool GravityForceGen::checkAddForce(Particle* p)
{
    return _active;
}

bool GravityForceGen::removeForceGenerator(Particle* p)
{
    return false;
}

