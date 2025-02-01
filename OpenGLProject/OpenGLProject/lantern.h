#pragma once
#include "sceneObject.h"
#include "objLoader.h"

class LanternObject : public SceneObject {
public:
	LanternObject() {
		Texture texture;
		texture.diffusePath = "C:\\GitHub\\OpenGLWorld\\OpenGLProject\\OpenGLProject\\textures\\lantern\\lantern_Base_Color.png";
		texture.roughnessPath = "C:\\GitHub\\OpenGLWorld\\OpenGLProject\\OpenGLProject\\textures\\lantern\\lantern_Roughness.png";
		texture.normalPath = "C:\\GitHub\\OpenGLWorld\\OpenGLProject\\OpenGLProject\\textures\\lantern\\lantern_Normal.png";

		auto material = std::make_shared<PBRMaterial>(texture);
		material->shininess = 5.0f;
		material->smoothness = 0.6f;

		CreateFromOBJ("meshes\\lantern.obj", material);

		Scale(glm::vec3(0.003f, 0.003f, 0.003f));
	}
};
