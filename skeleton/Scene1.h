#pragma once
#include "SceneTemplate.h"
class Scene1 : public SceneTemplate
{
public:
	Scene1(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~Scene1();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

