#pragma once
#include "material.h"
#include "PBRShader.h"

class PBRMaterial : public Material {
public:
	PBRMaterial(Texture texture) : PBRMaterial(texture.diffusePath, texture.roughnessPath, texture.normalPath) {}

    PBRMaterial(const std::string& diffusePath, const std::string& roughnessPath, const std::string& normalPath) : Material(PBRShader()) {
        diffuseMap = LoadTexture(diffusePath);
        roughnessMap = LoadTexture(roughnessPath);
		normalMap = LoadTexture(normalPath);
    }

	void Bind() const override {
        shader.SetInt("material.diffuse", 0);
        shader.SetInt("material.roughness", 1);
		shader.SetInt("material.normal", 2);
        shader.SetFloat("material.shininess", shininess);
        shader.SetFloat("material.smoothness", smoothness);
		shader.SetFloat("material.normalStrength", normalStrength);
        shader.SetFloat("lightStrength", 1.5f);
        shader.SetBool("useNormalMap", true);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffuseMap);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, roughnessMap);

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, normalMap);
	}

    GLuint diffuseMap = 0;
    GLuint roughnessMap = 0;
	bool useNormalMap = false;
	GLuint normalMap = 0;
    float shininess = 0;
    float smoothness = 0;
	float normalStrength = 1.0f;
};
