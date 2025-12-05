#include "WindTimerGenerator.h"
#include "PlayerEntity.h"
#include "RigidDynamic.h"
#include "Particle.h"
WindTimerGenerator::WindTimerGenerator(const Vector3& wVel, float k, float t)
    :ForceGenerator(Vector3(0.0, 0.0, 0.0))
{
    k1 = k;
    windVel = wVel;
    tmax = t;
    actTime = 0;
    increase = true;
}

WindTimerGenerator::~WindTimerGenerator()
{
}


void WindTimerGenerator::addForceToPxEntity(RigidDynamic* p)
{
   /* Vector3 velp = p->getVel();
    Vector3 force(k1 * (windVel - velp) + p->getK() *
        (windVel.magnitude() - velp.magnitude()) * (windVel - velp));
    p->addForce(force*actTime);
    */
}

bool WindTimerGenerator::checkAddForce(Particle* p)
{
    return _active;
}

bool WindTimerGenerator::removeForceGenerator(Particle* p)
{
    return false;
}

void WindTimerGenerator::addForceToParticle(Particle* p)
{
    Vector3 velp = p->getVel();
    Vector3 force(k1 * (windVel - velp) + p->getK() *
        (windVel.magnitude() - velp.magnitude()) * (windVel - velp));
    p->addForce(force*actTime);
}

void WindTimerGenerator::updateWindForce(double t)
{
    if (increase) {
        actTime += t;
        if (actTime > tmax) increase = false;
    }
    else {
        actTime -= t;
        if (actTime < 0) increase = true;
    }

}
