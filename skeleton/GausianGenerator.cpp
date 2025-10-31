#include "GausianGenerator.h"
#include "EntityManager.h"
GausianGenerator::GausianGenerator(EntityManager* m, Vector3 p, Vector3 _posVar, Vector3 v, Vector3 vr,
	double ms, Vector3 _velVar , Vector3 a,Vector3 _acVar, Vector4 _color, Vector4 _colorVar, double rd, int geprob, std::list<ForceGenerator*>* fl)
	:ParticleGenerator(m,p,v,vr,ms,a,rd,geprob,fl)
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
	if (generateProb > rand() % 101) {
		std::normal_distribution<float> _u(-0.5, 0.5);

		float auxx = _u(RANDOM);
		float auxy = _u(RANDOM);
		float auxz = _u(RANDOM);
		Vector3 p = pos + (posVar.multiply(Vector3(auxx, auxy, auxz)));
		auxx = _u(RANDOM);
		auxy = _u(RANDOM);
		auxz = _u(RANDOM);
		Vector3 v = vel + (velVar.multiply(Vector3(auxx, auxy, auxz)));
		auxx = _u(RANDOM);
		auxy = _u(RANDOM);
		auxz = _u(RANDOM);
		Vector3 a = ac + (acVar.multiply(Vector3(auxx, auxy, auxz)));
		auxx = _u(RANDOM);

		Vector4 c = color + (colorVar * auxx);
		double rd = r;
		Entity* e = mEntityManager->createMassParticle(p, v,velReal,mass, a, 0.999, 0, r, 1, 10.0, Vector3(0, 0, 0), c);
		e->setForceList(forceList);
	}
}
