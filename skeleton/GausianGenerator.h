#pragma once
#include "ParticleGenerator.h"
class GausianGenerator: public ParticleGenerator
{
private:
	
	std::mt19937 RANDOM;
	Vector3 velVar;
	Vector3 posVar;
protected:

public:
	GausianGenerator(EntityManager* m, Vector3 p,Vector3 _posVar, Vector3 v, Vector3 _velVar, Vector3 a, double rd);
	~GausianGenerator();
	virtual void generateParticle() override;
};

