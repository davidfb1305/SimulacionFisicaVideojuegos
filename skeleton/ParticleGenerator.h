#pragma once
#include "core.hpp"
#include <random>
class EntityManager;
class ParticleGenerator
{
private:
	
protected:
	EntityManager* mEntityManager;
	Vector3 pos;
	Vector3 vel;
	Vector3 ac;
	double r;
	bool active = true;
	int generateProb;
public:

	ParticleGenerator(EntityManager* m, Vector3 p = Vector3(0.0,0.0,0.0), Vector3 v = Vector3(0.0, 0.0, 0.0),
		Vector3 a = Vector3(0.0, 0.0, 0.0),double rd = 1.0,int genprob = 100);
	~ParticleGenerator();
	void setPos(Vector3 v);
	void setVel(Vector3 v);
	void setac(Vector3 v);
	void setR(double v); 
	const Vector3 getPos();
	const Vector3 getVel();
	const Vector3 getAc();
	const double getR();
	bool isActive();
	void setActive(bool b);
	virtual void generateParticle()=0;
};

