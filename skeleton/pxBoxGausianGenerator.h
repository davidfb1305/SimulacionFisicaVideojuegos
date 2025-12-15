#pragma once
#include "Generator.h"
class EntityManager;
class pxBoxGausianGenerator : public Generator
{
private:
	std::mt19937 RANDOM;
	Vector3 pos;
	Vector3 posVar;
	Vector3 initLVel;
	Vector3 initAngVel;
	Vector3 lVelVar;
	Vector3 angVelVar;
	Vector4 color;
	Vector4 colorVar;
	Vector3 size;
	Vector3 sizeVar;
	Vector3 material;
	Vector3 materialVar;
	float linearDamping;
	float angDamping;
	float mass;
	float k;
	float massVar;
	float time;
	EntityManager* mEntityManager;
	bool _blockZAxesMove = false;
protected:

public:
	pxBoxGausianGenerator(EntityManager* em, Vector3 p = Vector3(0.0, 0.0, 0.0), Vector3 pVar = Vector3(0.0, 0.0, 0.0), Vector3 lvel = Vector3(0.0, 0.0, 0.0),
		Vector3 lvelvar = Vector3(0.0, 0.0, 0.0), Vector3 angvel = Vector3(0.0, 0.0, 0.0), Vector3 angvelvar = Vector3(0.0, 0.0, 0.0),
		Vector3 mat = Vector3(1.0, 1.0, 1.0), Vector3 matVar = Vector3(0.0, 0.0, 0.0), float _mass = 1.0, float masvar = 0.0,
		Vector4 c = Vector4(1.0,1.0,1.0,1.0), Vector4 cvar = Vector4(0.0, 0.0, 0.0, 0.0), Vector3 s = Vector3(10.0,10.0,10.0),
		Vector3 svar = Vector3(0.0, 0.0, 0.0), float geprob = 100, float t = 10.0, int _max = 100.0, float linearD = 0.999, float angD =0.999,float k = 1.0,
		std::list<ForceGenerator*> fl = std::list<ForceGenerator*>()) ;
	void blockZAxesMove();
	void generate() override;
};

