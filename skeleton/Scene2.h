#pragma once
#include "SceneTemplate.h"
class Scene2 : public SceneTemplate
{
private:
protected:
public:
	Scene2(physx::PxPhysics* gPh);
	~Scene2();
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

