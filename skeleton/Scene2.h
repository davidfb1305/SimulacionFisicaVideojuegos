#pragma once
#include "SceneTemplate.h"
class ParticleSystem;
class Scene2 : public SceneTemplate
{
private:
	ParticleSystem* rain;
	ParticleSystem* fog;
	ParticleSystem* explosion;
protected:
public:
	Scene2(physx::PxPhysics* gPh);
	~Scene2();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

