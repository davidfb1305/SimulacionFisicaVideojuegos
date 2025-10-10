#pragma once
#include "core.hpp"
#include <random>
class EntityManager;
class ParticleGenerator
{
private:
	EntityManager* mEntityManager;
	Vector3 pos;
	Vector3 vel;
	Vector3 ac;
	double r;
protected:

public:

	ParticleGenerator(EntityManager* m, Vector3 p = Vector3(0.0,0.0,0.0), Vector3 v = Vector3(0.0, 0.0, 0.0),
		Vector3 a = Vector3(0.0, 0.0, 0.0),double rd);
	~ParticleGenerator();
	void setPos(Vector3 v);
	void setVel(Vector3 v);
	void setac(Vector3 v);
	void setR(double v); 
	const Vector3 getPos();
	const Vector3 getVel();
	const Vector3 getAc();
	const double getR();
	virtual void generateParticle()=0;
};

