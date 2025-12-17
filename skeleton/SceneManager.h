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
	bool flagNext = false;
	bool flagPrevious= false;
public:
	SceneManager();
	~SceneManager();
	void nextScene();
	void previousScene();
	void updateScene(double t);
	void addScene(SceneTemplate* newScene);
	void inputListener(unsigned char key, const  physx::PxTransform& camera);
	void setFlagNext();
	void setFlagPrevious();
	bool getFlagNext();
	bool getFlagPrevious();

};

