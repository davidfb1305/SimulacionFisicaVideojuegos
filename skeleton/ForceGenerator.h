#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include "Particle.h"
class ForceGenerator
{
private:
protected:
	bool _active = true;
	Vector3 forceToApply;
public:
	ForceGenerator(Vector3 force);
	virtual bool checkAddForce(Particle* p);
	virtual bool removeForceGenerator(Particle* p);
	virtual void addForceToParticle(Particle* p);
	virtual bool checkAddForceEntity(Entity* p);
	virtual void addForceToEntity(Entity* p); //WIP it will change to entity with volume
	void setActive(bool b);
	inline bool isActive() { return _active; };
	~ForceGenerator();
};

