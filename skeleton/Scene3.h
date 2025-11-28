#pragma once
#include "SceneTemplate.h"
class EntitySystem;
class whirlGenerator;
class windGenerator;
class GravityForceGen;
class Scene3 : public SceneTemplate
{

private:
	EntitySystem* prueba;
	whirlGenerator* _whirlGen;
	windGenerator* _windGen;
	GravityForceGen* _gravityGen;

protected:
public:
	Scene3(physx::PxPhysics* gPh, physx::PxScene* gScene);
	~Scene3();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

