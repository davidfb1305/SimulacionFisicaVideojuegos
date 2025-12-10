#include "windGenerator.h"
#include "PlayerEntity.h"
#include "RigidDynamic.h"
#include "Particle.h"
windGenerator::windGenerator(const Vector3& wVel, float k)
    :ForceGenerator(Vector3(0.0,0.0,0.0))
{
    k1 = k;
    windVel = wVel;
}

windGenerator::~windGenerator()
{
}

void windGenerator::addForceToPxEntity(RigidDynamic* p)
{

    Vector3 velp = p->getLinearVel();
    Vector3 force(k1 * (windVel - velp) + p->getK() *
        (windVel.magnitude() - velp.magnitude()) * (windVel - velp));
    p->addForce(force);
}

bool windGenerator::checkAddForce(Particle* p)
{
    return _active;
}

bool windGenerator::removeForceGenerator(Particle* p)
{
    return false;
}

void windGenerator::addForceToParticle(Particle* p)
{
    Vector3 velp = p->getVel();
    Vector3 force(k1 * (windVel - velp) + p->getK() *
        (windVel.magnitude() - velp.magnitude()) * (windVel - velp));
    p->addForce(force);
}
