#pragma once
#include "SceneTemplate.h"
class Scene5 : public SceneTemplate
{
private:

protected:

public:
	Scene5(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~Scene5();
	void loadScene() override;

};

