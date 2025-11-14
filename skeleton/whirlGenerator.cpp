#include "whirlGenerator.h"
#include "Particle.h"
whirlGenerator::whirlGenerator(Vector3 o, float k)
    :ForceGenerator(Vector3(0.0, 0.0, 0.0)) {
    k1 = k;
    origin = o;
}

whirlGenerator::~whirlGenerator()
{
}

bool whirlGenerator::checkAddForce(Particle* p)
{
    return _active;
}

bool whirlGenerator::removeForceGenerator(Particle* p)
{
    return false;
}

void whirlGenerator::addForceToParticle(Particle* p)
{
    Vector3 velp = p->getVel();
    windVel = k1 * Vector3(-(p->getPos().z-origin.z),50-(p->getPos().y-origin.y), p->getPos().x - origin.x);
    Vector3 force(k1 * (windVel - velp) + p->getK() *
        (windVel.magnitude() - velp.magnitude()) * (windVel - velp));
    p->addForce(force);
}
