#include "scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Draw()
{
	for (std::shared_ptr<SceneObject>& object : objects)
	{
		object->Draw(std::make_shared<Scene>(*this));
	}
}

void Scene::Update()
{
}
