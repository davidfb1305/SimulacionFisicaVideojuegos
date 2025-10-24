#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"
#include "Entity.h"
class ForceGenerator
{
private:
protected:
	Vector3 forceToApply;
public:
	ForceGenerator(Vector3 force);
	virtual bool checkAddForce(Entity* p);
	virtual bool removeForceGenerator(Entity* p);
	void addForceToParticle(Entity* p);
	~ForceGenerator();
};

