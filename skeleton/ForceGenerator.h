#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include "Entity.h"
class Particle;
class RigidDynamic;
class PlayerEntity;
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
	virtual void addForceToPxEntity(RigidDynamic* p);
	void setActive(bool b);
	inline bool isActive() { return _active; };
	~ForceGenerator();
};

