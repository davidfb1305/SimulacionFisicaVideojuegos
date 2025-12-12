#include "BuoyancyForceGenerator.h"
#include "Entity.h"
#include "RigidDynamic.h"
#include "Particle.h"
BuoyancyForceGenerator::BuoyancyForceGenerator(Entity* e,float h, float v, float d, float g)
	: ForceGenerator(Vector3(0,0,0)){
	_refEntity = e;
	_height = h;
	_volume = v;
	_liquidDensity = d;
	_gravity = g;

}

BuoyancyForceGenerator::~BuoyancyForceGenerator()
{
}


bool BuoyancyForceGenerator::checkAddForce(Particle* p)
{
	return _active;
}

void BuoyancyForceGenerator::addForceToPxEntity(mRigidDynamic* p)
{
	float h = p->getGlobalPos().y;
	float h0 = _refEntity->mtrans->p.y;
	float inmersed = 0.0;
	float hobj = p->getVolumeVec().y;
	if (h - h0 > hobj * 0.5) {
		inmersed = 0.0;
	}
	else if (h0 - h > hobj * 0.5) {
		inmersed = 1.0;
	}
	else {
		inmersed = (h0 - h) / (hobj + 0.5);
	}
	//volumen de la entidad
	forceToApply = Vector3(0.0, _liquidDensity * p->getVolume() * inmersed * _gravity, 0.0);
	p->addForce(forceToApply);
}


void BuoyancyForceGenerator::addForceToParticle(Particle* p)
{
	float h = p->getPos().y;
	float h0 = _refEntity->mtrans->p.y;
	float inmersed = 0.0;
	if (h - h0 > _height * 0.5) {
		inmersed = 0.0;
	}
	else if (h0 - h > _height * 0.5) {
		inmersed = 1.0;
	}
	else {
		inmersed = (h0 - h)/(_height+0.5);
	}
	forceToApply = Vector3(0.0, _liquidDensity * _volume * inmersed *_gravity,0.0);
	p->addForce(forceToApply);

}
