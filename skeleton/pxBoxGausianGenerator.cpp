#include "pxBoxGausianGenerator.h"
#include "EntityManager.h"
#include "RigidDynamic.h"
pxBoxGausianGenerator::pxBoxGausianGenerator(EntityManager* em,Vector3 p, Vector3 pVar, Vector3 lvel, Vector3 lvelvar, Vector3 angvel,
	Vector3 angvelvar, Vector3 mat, Vector3 matVar, float _mass, float masvar,
	Vector4 c, Vector4 cvar, Vector3 s, Vector3 svar, float geprob, float t, int _max, 
	std::list<ForceGenerator*> fl) : Generator(_max)
{
	mEntityManager = em;
	pos = p;
	posVar = pVar;
	initLVel = lvel;
	lVelVar = lvelvar;
	initAngVel = angvel;
	angVelVar = angvelvar;
	color = c;
	colorVar = cvar;
	size  = s;
	sizeVar = svar;
	generateProb = geprob;
	time = t;
	material = mat;
	materialVar = matVar;
	mass = _mass;
	massVar = masvar;
	std::random_device __randomDevice;
	RANDOM = std::mt19937(__randomDevice());
	forceList = fl;
	active = true;
}

void pxBoxGausianGenerator::generate()
{
	if (entityList.size() == _maxEntities) return;
	if (generateProb > rand() % 101) {
		std::normal_distribution<float> _u(-0.5, 0.5);
		//pos
		float auxx = _u(RANDOM);
		float auxy = _u(RANDOM);
		float auxz = _u(RANDOM);
		Vector3 p = pos + (posVar.multiply(Vector3(auxx, auxy, auxz)));
		//linear vel
		auxx = _u(RANDOM);
		auxy = _u(RANDOM);
		auxz = _u(RANDOM);
		Vector3 lv = initLVel + (lVelVar.multiply(Vector3(auxx, auxy, auxz)));
		//ang vel
		auxx = _u(RANDOM);
		auxy = _u(RANDOM);
		auxz = _u(RANDOM);
		Vector3 angv = initAngVel + (angVelVar.multiply(Vector3(auxx, auxy, auxz)));
		//size
		auxx = abs(_u(RANDOM));
		auxy = abs(_u(RANDOM));
		auxz = abs(_u(RANDOM));
		Vector3 s = size + (sizeVar.multiply(Vector3(auxx, auxy, auxz)));
		//material
		auxx = abs(_u(RANDOM));
		auxy = abs(_u(RANDOM));
		auxz = abs(_u(RANDOM));
		Vector3 m = material + (materialVar.multiply(Vector3(auxx, auxy, auxz)));
		//mass
		auxx = _u(RANDOM);
		float _m = mass + (massVar * auxx);
		//color
		auxx = _u(RANDOM);
		auxy = _u(RANDOM);
		auxz = _u(RANDOM);
		Vector4 c = color + (colorVar.multiply(Vector4(auxx, auxy, auxz,_m)));
		
		RigidDynamic* e = mEntityManager->createPxBox(p,lv,angv,m,s,c,10.0);
		
		entityList.push_back(e);
		e->setRemoveConTime(5);
		e->setParentListPointer(&entityList);
		e->setForceList(forceList);
		e->setParentListPointer(&entityList);
	
	}
}
