#pragma once
#include "SceneTemplate.h"
class Scene4 : public SceneTemplate
{
private:

protected:

public:
	Scene4(physx::PxPhysics* gPh);
	~Scene4();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

