#pragma once
#include "sceneObject.h"
#include <vector>
#include "camera.h"

class Scene : public std::enable_shared_from_this<Scene>
{
public:
	Scene();
	~Scene();
	void Draw(float deltaTime);
	virtual void Update() = 0;
	void AddObject(const std::shared_ptr<SceneObject>& object) { objects.push_back(object); }
    void SetCamera(const std::shared_ptr<Camera>& camera) { currentCamera = camera; }
	glm::mat4 GetViewMatrix() const { return currentCamera->GetViewMatrix(); }
	glm::mat4 GetProjectionMatrix() const { return glm::perspective(glm::radians(60.0f), 1920.0f / 1080.0f, 0.1f, 100.0f); }
	glm::vec3 GetCameraPosition() const { return currentCamera->Position; }
	glm::vec3 GetLightPosition() const { return glm::vec3(2, 5.0f, 0.0f); }
	glm::vec3 GetLightColor() const { return glm::vec3(1.0f, 1.0f, 1.0f); }
	float getLightStrength() const { return 1.5f; }

private:
	std::vector<std::shared_ptr<SceneObject>> objects;
	std::shared_ptr<Camera> currentCamera;
	std::shared_ptr<Scene> thisScene;
};