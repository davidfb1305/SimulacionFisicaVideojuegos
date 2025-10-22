#include "GausianGenerator.h"
#include "EntityManager.h"
GausianGenerator::GausianGenerator(EntityManager* m, Vector3 p, Vector3 _posVar, Vector3 v, Vector3 _velVar , Vector3 a,Vector3 _acVar, Vector4 _color, Vector4 _colorVar, double rd)
	:ParticleGenerator(m,p,v,a,rd)
{
    std::random_device __randomDevice;
	RANDOM = std::mt19937(__randomDevice());
	velVar = _velVar;
	acVar = _acVar;
	color = _color;
	colorVar = _colorVar;
	posVar = _posVar;
}

GausianGenerator::~GausianGenerator()
{
}

void GausianGenerator::generateParticle()
{
	std::normal_distribution<float> _u(-0.5, 0.5 );

	float aux = _u(RANDOM);
	Vector3 p = pos + (posVar * aux);
	aux = _u(RANDOM);
	Vector3 v  = vel +(velVar * aux);
	aux = _u(RANDOM);
	Vector3 a = ac + (acVar *aux);
	aux = _u(RANDOM);
	Vector4 c = color + (colorVar * aux);
	double rd = r ;
	mEntityManager->createParticle(p, v, a, 0.999, 0, r,1,3.0,Vector3(0,0,0),c);

}
