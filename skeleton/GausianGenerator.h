#pragma once
#include "ParticleGenerator.h"
class GausianGenerator: public ParticleGenerator
{
private:
	
	std::mt19937 RANDOM;
	Vector3 velVar;
	Vector3 posVar;
	Vector3 acVar;
	Vector4 color;
	Vector4 colorVar;
	
protected:

public:
	GausianGenerator(EntityManager* m, Vector3 p,Vector3 _posVar, Vector3 v, Vector3 _velVar, Vector3 a,Vector3 _acVar,Vector4 _color, Vector4 _colorVar, double rd, int geprob);
	~GausianGenerator();
	virtual void generateParticle() override;
};

