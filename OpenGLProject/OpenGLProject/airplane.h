#pragma once
#include "sceneObject.h"
#include "objLoader.h"
#include "materials.h"

class AirplaneObject : public SceneObject {
public:
	AirplaneObject() {
		auto sandMaterial = std::make_shared<SandMaterial>();
		CreateFromOBJ("C:\\GitHub\\OpenGLWorld\\OpenGLProject\\OpenGLProject\\meshes\\PlayerCharacter.obj", sandMaterial);
	}
};