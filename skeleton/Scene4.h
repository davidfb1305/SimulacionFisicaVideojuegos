#pragma once
#include "SceneTemplate.h"
class SpringForceGenerator;
class GravityForceGen;
class Scene4 : public SceneTemplate
{
private:

protected:
	//particle point
	SpringForceGenerator* spring;
	//particle to particle
	SpringForceGenerator* spring1;
	SpringForceGenerator* spring2;
	GravityForceGen* g;
	Entity* p1;
	Entity* p2;
	Entity* p3;
public:
	Scene4(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~Scene4();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

