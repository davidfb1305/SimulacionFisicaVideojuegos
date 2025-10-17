#include "GausianGenerator.h"
#include "EntityManager.h"
GausianGenerator::GausianGenerator(EntityManager* m, Vector3 p, Vector3 _posVar, Vector3 v, Vector3 _velVar , Vector3 a, double rd)
	:ParticleGenerator(m,p,v,a,rd)
{
    std::random_device __randomDevice;
	RANDOM = std::mt19937(__randomDevice());
	velVar = _velVar;
	posVar = _posVar;
}

GausianGenerator::~GausianGenerator()
{
}

void GausianGenerator::generateParticle()
{
	std::normal_distribution<float> _u(0, 1 );

	float aux = _u(RANDOM);
	Vector3 p = pos + (posVar * aux);
	aux = _u(RANDOM);
	Vector3 v  = vel +(velVar * aux);
	Vector3 a = ac;
	double rd = r ;
	mEntityManager->createParticle(p, v, a, 0.999, 0, r,1,3.0);

}
