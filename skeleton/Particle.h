#pragma once
#include "Entity.h"
#include <list>
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
	physx::PxVec3 maxdistance;

	double massReal = 0.0;
	Vector3 velReal;
	double massSim = 0.0;
	double k = 0.0;
	//Valet only
	physx::PxVec3 lastpos;
	void integrate(double t);
	void addForces() override;
public:
	Particle(const Vector3& p = Vector3(0.0, 0.0, 0.0), const Vector3& v = Vector3(0.0, 0.0, 0.0),
		const Vector3& a = Vector3(0.0, 0.0, 0.0) ,double d = 0.999, int mt = 0.0, int rc = 0, 
	int rct = 0, Vector3 maxdis = Vector3(0.0, 0.0, 0.0), Vector3& vr = Vector3(1.0, 1.0, 1.0), double mass = 1);
	void setLastPos(Vector3 a);
	void setMass(double d);
	inline void setK(double d) { k = 1.0; };
	inline double getK() { return k; };
	inline const Vector3& getPos() { return mtrans->p; };
 	inline const Vector3 getVel() { return vel; };
	bool uptadeDestroyCondition(double t);
	~Particle();
	virtual bool update(double t) override;
	

};

