#include "PlayerEntity.h"
#include "ParticleSystem.h"
#include "GausianGenerator.h"
#include "ForceGenerator.h"
#include "EntityManager.h"
PlayerEntity::PlayerEntity(const Vector3 initPos, physx::PxPhysics* gP, EntityManager* em)
	:Entity()
{
	vel = Vector3(0,0,0);
	ac = Vector3(0,0,0);
	jetPackForce = new ForceGenerator(Vector3(0,0,0));
	lastpos = initPos;
	_jetPackPS = new ParticleSystem(em);
	//Rain gausian
	_jetPackPS->addGenerator(new GausianGenerator(em, Vector3(initPos+Vector3(0,-2,0)), Vector3(0, 0, 0),
		Vector3(0.0, -1.0, 0.0), Vector3(1.0, 1.0, 1.0), 1, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0),
		Vector3(0, 0, 0), Vector4(1.0, 0.0, 0.0, 1.0), Vector4(0, 0, 0.5, 0), 1, 100));
	em->addEntity(_jetPackPS);
	jetPackForceForParticles = new ForceGenerator(Vector3(0, -20, 0));
	_jetPackPS->addForceGenerator(jetPackForceForParticles);

}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::inputListener(unsigned char key)
{
	switch (toupper(key))
	{
	case 'Z': {
		_jetPackPS->setActive(!_jetPackPS->isActive());
		jetPackForce->setActive(jetPackForce->isActive());
		break;
		}
	}
}
void PlayerEntity::integrate(double t) {
	vel += (t * ac);
	mtrans->p += (t * vel);
	Vector3 aux = mtrans->p - lastpos;
	lastpos = mtrans->p;
	_jetPackPS->updatePos(aux);

}
void PlayerEntity::addForces()
{
	for (ForceGenerator* f : forceList) {
		if (f->checkAddForceEntity(this)) f->addForceToEntity(this);
	}
}
bool PlayerEntity::update(double t)
{
	clearForce();
	addForces();
	ac = forceToAdd * pow(mass, -1);
	integrate(t);
    return true;
}
