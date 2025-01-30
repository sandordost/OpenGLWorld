#pragma once
#include "sceneObject.h"
#include "objLoader.h"

class AirPlaneObject : public SceneObject {
public:
	AirPlaneObject() {
		auto sandMaterial = std::make_shared<SandMaterial>();
		CreateFromOBJ("C:\\GitHub\\OpenGLWorld\\OpenGLProject\\OpenGLProject\\meshes\\PlayerCharacter.obj", sandMaterial);
	}
};