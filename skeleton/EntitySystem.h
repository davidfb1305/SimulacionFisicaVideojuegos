#pragma once
#include "Entity.h"
#include "Particle.h"
#include "Generator.h"
#include <list>
class EntityManager;
class ForceGenerator;
class EntitySystem : public Entity
{
private:

	std::list<Generator*> generatorList;
	std::list<ForceGenerator*>  myForceList;
	EntityManager* mEntityManager;
	
protected:

public:
	EntitySystem(EntityManager* em);
	void addGenerator(Generator* pg);
	void addGenForce(ForceGenerator* fg);
	void remove(ForceGenerator* fg);
	void updatePos(Vector3 v);
	~EntitySystem();
	virtual bool update(double t) override;
};

