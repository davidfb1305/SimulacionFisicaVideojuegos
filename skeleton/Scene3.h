#pragma once
#include "SceneTemplate.h"
class ParticleSystem;
class whirlGenerator;
class windGenerator;
class GravityForceGen;
class Scene3 : public SceneTemplate
{

private:
	ParticleSystem* prueba;
	whirlGenerator* _whirlGen;
	windGenerator* _windGen;
	GravityForceGen* _gravityGen;

protected:
public:
	Scene3(physx::PxPhysics* gPh);
	~Scene3();
	void loadScene() override;
	void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

