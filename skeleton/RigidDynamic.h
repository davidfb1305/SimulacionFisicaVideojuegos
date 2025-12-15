#pragma once
#include "Entity.h"
class mRigidDynamic : public Entity
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
	void inline setVolumeVec(const Vector3& v) { volumeVec = v; };
public:

	mRigidDynamic(physx::PxScene* mS);
	mRigidDynamic(mRigidDynamic&&) = default;
	mRigidDynamic& operator=(mRigidDynamic&&) = default;
	mRigidDynamic(const mRigidDynamic&) = delete;
	mRigidDynamic& operator=(const mRigidDynamic&) = delete;
	~mRigidDynamic();
	physx::PxRigidDynamic* getPxRigidDynamic();
	bool updateDestroyCondition(double t) override;
	Vector3 getLinearVel();
	Vector3 getGlobalPos();
	bool update(double t) override;
	void addForces() override;
	float getVolume();
	Vector3 inline getVolumeVec() { return volumeVec; };
	void inline setK(float _k) { k = _k; };
	float getK() { return k; };
};

