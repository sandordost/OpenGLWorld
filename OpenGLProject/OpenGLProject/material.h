#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include "textureLoader.h"
#include "shader.h"
#include "texture.h"

// Only supports PBR materials
class Material {
public:
	Material(const Shader& shader);

    virtual void Bind() const = 0;

	static GLuint CreateSolidColorTexture(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	Shader GetShader() const { return shader; }

protected:
	Shader shader;
	GLuint LoadTexture(const std::string& path);

};
