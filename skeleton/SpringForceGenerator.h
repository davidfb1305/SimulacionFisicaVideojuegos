#pragma once
#include "ForceGenerator.h"
#include "Entity.h"
class SpringForceGenerator: public ForceGenerator
{
private:
	double _k;
	double _resting_length;
	Entity* _ori;
protected:

public:
	SpringForceGenerator(Entity* ori, double k, double resting_length);
	~SpringForceGenerator();
	void addForceToParticle(Particle* p) override;
	inline void setK(double k) { _k = k; };
	inline const double getK() { return _k; };
	inline void setLength(double l) { _resting_length = l; };

};

