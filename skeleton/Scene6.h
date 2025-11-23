#pragma once
#include "SceneTemplate.h"
class Scene6 :
    public SceneTemplate
{
    private:
    
    protected:
    
    public:
        Scene6(physx::PxPhysics* gPh, physx::PxScene* gScene);
        ~Scene6();
        void loadScene() override;
        void inputListener(unsigned char key, const physx::PxTransform& camera) override;
};

