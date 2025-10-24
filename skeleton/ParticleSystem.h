#pragma once
#include "Entity.h"
#include "Particle.h"
#include "ParticleGenerator.h"
#include <list>
class EntityManager;
class ForceGenerator;
class ParticleSystem : public Entity
{
private:

	std::list<ParticleGenerator*> generatorList;
	std::list<ForceGenerator*>  myForceList;
	EntityManager* mEntityManager;
	
protected:

public:
	ParticleSystem(EntityManager* em);
	void addGenerator(ParticleGenerator* pg);
	void addForce(ForceGenerator* fg);
	void remove(ForceGenerator* fg);
	~ParticleSystem();
	virtual bool update(double t) override;
};

