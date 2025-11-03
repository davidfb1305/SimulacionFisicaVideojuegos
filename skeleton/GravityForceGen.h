#pragma once
#include "ForceGenerator.h"
class GravityForceGen : public ForceGenerator
{
private:
protected:
public:
	GravityForceGen();
	~GravityForceGen();
	bool checkAddForce(Particle* p) override;
	bool removeForceGenerator(Particle* p) override;
};

