#include "scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Draw(float deltaTime)
{
	std::shared_ptr<Scene> scenePtr = shared_from_this();

	for (std::shared_ptr<SceneObject>& object : objects)
	{
		object->Animate(deltaTime);
		object->Draw(scenePtr);
	}
}