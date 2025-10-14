#pragma once
#include "SceneTemplate.h"
#include <vector>
using namespace std;
class SceneManager
{
private:
	vector<SceneTemplate*> scenes;
	SceneTemplate* actScene;
	int actSceneIndex;
	physx::PxPhysics* gPh;
protected:

public:
	SceneManager();
	~SceneManager();
	void nextScene();
	void previousScene();
	void updateScene(double t);
	void addScene(SceneTemplate* newScene);
};

