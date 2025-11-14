#pragma once
#include "SceneTemplate.h"
class SpringForceGenerator;
class Scene4 : public SceneTemplate
{
private:

protected:
	SpringForceGenerator* spring;
	Entity* p1;
	Entity* p2;
public:
	Scene4(physx::PxPhysics* gPh);
	~Scene4();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

