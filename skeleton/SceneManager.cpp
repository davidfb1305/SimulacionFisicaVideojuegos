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
	if (scenes.size() == 1) return;
	if (actSceneIndex == scenes.size() - 1) actSceneIndex = 0;
	else actSceneIndex++;
	actScene->unLoadScene();

	actScene = scenes[actSceneIndex];
	actScene->loadScene();
	flagNext = false;
}

void SceneManager::previousScene()
{
	if (scenes.size() == 1) return;
	if (actSceneIndex == 0) actSceneIndex = (scenes.size() - 1);
	else actSceneIndex--;
	actScene->unLoadScene();
	actScene = scenes[actSceneIndex];
	actScene->loadScene();
	flagPrevious = false;
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

void SceneManager::setFlagNext()
{
	flagNext = true;
}

void SceneManager::setFlagPrevious()
{
	flagPrevious = true;
}

bool SceneManager::getFlagNext()
{
	return flagNext;
}

bool SceneManager::getFlagPrevious()
{
	return flagPrevious;
}
