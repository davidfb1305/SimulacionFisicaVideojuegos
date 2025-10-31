#pragma once
#include "SceneTemplate.h"
class ParticleSystem;
class Scene3 : public SceneTemplate
{

private:
	ParticleSystem* prueba;
protected:
public:
	Scene3(physx::PxPhysics* gPh);
	~Scene3();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

