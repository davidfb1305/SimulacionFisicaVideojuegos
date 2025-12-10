#pragma once
#include "SceneTemplate.h"
class windGenerator;
class Scene6 :
    public SceneTemplate
{
    private:
    
    protected:
        windGenerator* wind;
    public:
        Scene6(physx::PxPhysics* gPh, physx::PxScene* gScene);
        ~Scene6();
        void loadScene() override;
        void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

