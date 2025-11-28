#pragma once
#include "core.hpp"
#include <list>
#include <random>
#include "Generator.h"
class EntityManager;
class ForceGenerator;
class ParticleGenerator : public Generator
{
private:
	
protected:
	EntityManager* mEntityManager;
	Vector3 vel;
	Vector3 velReal;
	Vector3 ac;
	double mass;
	float time;
	double r;
	bool active = true;
	int generateProb;
public:

	ParticleGenerator(EntityManager* m, Vector3 p = Vector3(0.0, 0.0, 0.0), Vector3 v = Vector3(0.0, 0.0, 0.0), Vector3 vr = Vector3(1.0, 1.0, 1.0),
		double ms = 1.0,Vector3 a = Vector3(0.0, 0.0, 0.0), double rd = 1.0, int genprob = 100,float t= 10.0,std::list<ForceGenerator*> fl = std::list<ForceGenerator*>());
	~ParticleGenerator();
	void setPos(Vector3 v);
	void setVel(Vector3 v);
	void setac(Vector3 v);
	void addForceGen(ForceGenerator* f);
	void setR(double v); 
	const Vector3 getPos();
	const Vector3 getVel();
	const Vector3 getAc();
	const double getR();
	virtual void generate() override;
};

