#pragma once
#include "ForceGenerator.h"
class WindTimerGenerator : public ForceGenerator
{
private:
	Vector3 windVel;
	float k1;
	float tmax;
	float actTime;
	bool increase;
protected:

public:
	WindTimerGenerator(const Vector3& wVel, float k, float t);
	~WindTimerGenerator();
	void addForceToEntity(PlayerEntity* p) override;
	bool checkAddForce(Particle* p) override;
	bool removeForceGenerator(Particle* p) override;
	void addForceToParticle(Particle* p) override;
	void updateWindForce(double t);
};

