#pragma once
#include "ForceGenerator.h"

class windGenerator : public ForceGenerator
{
private:
	Vector3 windVel;
	float k1;
protected:

public:
	windGenerator(const Vector3& wVel, float k);
	~windGenerator();
	bool checkAddForce(Particle* p) override;
	bool removeForceGenerator(Particle* p) override;
	void addForceToParticle(Particle* p) override;
};

