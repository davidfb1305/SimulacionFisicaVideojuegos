#pragma once
#include "Entity.h"
#include "Particle.h"
#include "ParticleGenerator.h"
#include <list>
class EntityManager;
class ParticleSystem : public Entity
{
private:
	std::list<ParticleGenerator*> generatorList;
	EntityManager* mEntityManager;
	
protected:

public:
	ParticleSystem(EntityManager* em);
	void addGenerator(ParticleGenerator* pg);
	~ParticleSystem();
	virtual bool update(double t) override;
};

