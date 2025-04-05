#pragma once
#include "sceneObject.h"
#include "materials.h"

class TreeObject : public SceneObject {
public:
	TreeObject() {
		auto treeMaterial = std::make_shared<CarMaterial>();
		CreateFromOBJ("meshes/Small house.obj", treeMaterial);
		Scale(glm::vec3(0.65f, 0.65f, 0.65f));
	}
};