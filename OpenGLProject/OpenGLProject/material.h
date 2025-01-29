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
	Material(const Texture& texture, float shininess, float smoothness);
    Material(const std::string& diffusePath, const std::string& roughnessPath, float shininess, float smoothness);

    void Bind(const Shader& shader) const;
    void Unbind() const;

    GLuint GetDiffuseMap() const { return diffuseMap; }
    GLuint GetRoughnessMap() const { return roughnessMap; }
    float GetShininess() const { return shininess; }
	static GLuint CreateSolidColorTexture(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

private:
    GLuint diffuseMap;
    GLuint roughnessMap;
    float shininess;
    float smoothness;

    GLuint LoadTexture(const std::string& path);
};
