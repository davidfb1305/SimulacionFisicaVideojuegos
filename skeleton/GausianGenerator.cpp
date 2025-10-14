#include "GausianGenerator.h"

GausianGenerator::GausianGenerator(EntityManager* m, Vector3 p, Vector3 v, Vector3 a, double rd)
	:ParticleGenerator(m,p,v,a,rd)
{

}

GausianGenerator::~GausianGenerator()
{
}

void GausianGenerator::generateParticle()
{
	std::normal_distribution<double> _u{ -1,1 };
	//Vector3 p = pos + (pos*  _u.  (std::mt19937)) ;
	Vector3 v ;
	Vector3 a ;
	double rd ;
}
