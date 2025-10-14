#pragma once
#include "SceneTemplate.h"
class Scene1 : public SceneTemplate
{
public:
	Scene1(physx::PxPhysics* gPh);
	~Scene1();
	virtual void loadScene() override;
};

