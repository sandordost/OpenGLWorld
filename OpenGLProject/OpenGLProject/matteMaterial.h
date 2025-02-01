#pragma once
#include "material.h"
#include "matteShader.h"

class MatteMaterial : public Material {
public:
	MatteMaterial() : MatteMaterial(128, 128, 128, 255) {}

	MatteMaterial(const Texture& texture) : Material(MatteShader()) {
		diffuseMap = LoadTexture(texture.diffusePath);
	}

	MatteMaterial(char r, char g, char b, char a) : Material(MatteShader()) {
		diffuseMap = CreateSolidColorTexture(r, g, b, a);
	}
	MatteMaterial(const std::string& diffusePath) : Material(MatteShader()), diffuseMap(LoadTexture(diffusePath)){}

	void Bind() const override {
		shader.SetInt("material.diffuse", 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);
	}

	GLuint diffuseMap = 0;
};