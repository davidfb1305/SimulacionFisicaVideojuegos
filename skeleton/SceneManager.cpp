#include "SceneManager.h"

SceneManager::SceneManager()
{
	
	scenes = vector<SceneTemplate*>();
	actSceneIndex = 0;
	actScene = nullptr;
}

SceneManager::~SceneManager()
{
}

void SceneManager::nextScene()
{
	if (actSceneIndex == scenes.size() - 1) actSceneIndex = 0;
	actScene->unLoadScene();
	actScene = scenes[actSceneIndex + 1];
	actScene->loadScene();
}

void SceneManager::previousScene()
{
	if (actSceneIndex == 0) actSceneIndex = (scenes.size() - 1);
	actScene->unLoadScene();
	actScene = scenes[actSceneIndex - 1];
	actScene->loadScene();
}

void SceneManager::updateScene(double t)
{
	actScene->update(t);
}

void SceneManager::addScene(SceneTemplate* newScene)
{
	scenes.push_back(newScene);
	if (actScene == nullptr) { actScene = newScene; 
	actScene->loadScene();
	}
}
void SceneManager::inputListener(unsigned char key, const  physx::PxTransform& camera) {
	actScene->inputListener(key, camera);
}