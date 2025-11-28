#pragma once
#include "SceneTemplate.h"
class EntitySystem;
class Scene2 : public SceneTemplate
{
private:
	EntitySystem* rain;
	EntitySystem* fog;
	EntitySystem* explosion;
protected:
public:
	Scene2(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~Scene2();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

