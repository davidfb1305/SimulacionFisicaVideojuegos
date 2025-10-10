#pragma once
#include "Entity.h"
enum MoveType
{
	SemiEuler= 0,
	Euler,
	Valet

};
enum RemoveCondition {
	NONE = 0,
	TIME,
	DISTANCE
};

class Particle: public Entity
{
protected:
	physx::PxVec3 vel;
	physx::PxVec3 ac;
	double dumping;
	MoveType mMt;
	RemoveCondition mRc;
	double timeToRemove;
	physx::PxVec3 initpos;
	physx::PxVec3 maxpos;
	physx::PxVec3 maxistance;

	//Valet only
	physx::PxVec3 lastpos;
	void integrate(double t);
public:
	Particle();
	Particle(const Vector3& v = Vector3(0.0, 0.0, 0.0), const Vector3& a = Vector3(0.0, 0.0, 0.0),double d= 0.999, int mt = 0.0);
	void setLastPos(Vector3 a);
	bool uptadeDestroyCondition(double t);
	~Particle();
	virtual bool update(double t) override;
};

