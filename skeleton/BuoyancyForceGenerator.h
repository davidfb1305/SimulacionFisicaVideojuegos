#pragma once
#include "ForceGenerator.h"

class BuoyancyForceGenerator : public ForceGenerator
{
private:
	float _height;
	float _volume;
	float _liquidDensity;
	float _gravity;
	Entity* _refEntity;
protected:

public:
	BuoyancyForceGenerator(Entity* e,float h, float v, float d, float g = 9.8);
	~BuoyancyForceGenerator();
	bool checkAddForce(Particle* p) override;
	void addForceToParticle(Particle* p) override;
};

