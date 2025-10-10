#pragma once
#include "ParticleGenerator.h"
class GausianGenerator: public ParticleGenerator
{
private:

protected:

public:
	GausianGenerator(EntityManager* m, Vector3 p, Vector3 v, Vector3 a, double rd);
	~GausianGenerator();
	virtual void generateParticle() override;
};

