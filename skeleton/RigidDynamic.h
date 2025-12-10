#pragma once
#include "Entity.h"
class RigidDynamic : public Entity
{
private:
protected:
	physx::PxRigidDynamic* _mRigid;
	friend class EntityManager;
	physx::PxScene* mScene;
	float volume = 0.0f;
	Vector3 volumeVec;
	float k = 1.0;
	float mass;
	void setVolume(float f);
	void setLinearDamping(float d);
	void setAngularDamping(float d);
	void inline setK(float _k) { k = _k; };
	void inline setVolumeVec(const Vector3& v) { volumeVec = v; };
public:
	RigidDynamic(physx::PxScene* mS);
	~RigidDynamic();
	physx::PxRigidDynamic* getPxRigidDynamic();
	bool updateDestroyCondition(double t) override;
	Vector3 getLinearVel();
	float inline getK() { return k; };
	Vector3 getGlobalPos();
	virtual bool update(double t) override;
	void addForces() override;
	float getVolume();
	Vector3 inline getVolumeVec() { return volumeVec; };
};

