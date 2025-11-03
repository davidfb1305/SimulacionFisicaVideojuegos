#pragma once
#include "ForceGenerator.h"
class whirlGenerator : public ForceGenerator
{
private:
	Vector3 windVel;
	Vector3 origin;
	float k1;
protected:
public:
	whirlGenerator(Vector3 o,float k);
	~whirlGenerator();
	bool checkAddForce(Particle* p) override;
	bool removeForceGenerator(Particle* p) override;
	void addForceToParticle(Particle* p) override;
};

