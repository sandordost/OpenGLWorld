#pragma once
#include "sceneObject.h"
#include "materials.h"

class CarObject : public SceneObject {
public:
	CarObject() {
		auto carMaterial = std::make_shared<CarMaterial>();
		CreateFromOBJ("meshes/car.obj", carMaterial);
		Scale(glm::vec3(0.65f, 0.65f, 0.65f));
	}
};