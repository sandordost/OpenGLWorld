#include "material.h"

Material::Material(const Texture& texture, float shininess, float smoothness)
    : Material(texture.diffusePath, texture.roughnessPath, shininess, smoothness) { };

Material::Material(const std::string& diffusePath, const std::string& roughnessPath, float shininess, float smoothness)
    : shininess(shininess), smoothness(smoothness) {

    if (diffusePath.empty()) {
        diffuseMap = CreateSolidColorTexture(128, 128, 128, 255);
    }
    else {
		diffuseMap = LoadTexture(diffusePath);
    }

	if (roughnessPath.empty()) {
		roughnessMap = CreateSolidColorTexture(128, 128, 128, 255);
	}
    else {
		roughnessMap = LoadTexture(roughnessPath);
    }
}

void Material::Bind(const Shader& shader) const {

    shader.SetInt("material.diffuse", 0);
    shader.SetInt("material.roughness", 1);
    shader.SetFloat("material.shininess", shininess);
	shader.SetFloat("material.smoothness", smoothness);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, roughnessMap);
}

void Material::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Material::LoadTexture(const std::string& path) {
	TextureLoader texLoader;

	return texLoader.LoadTexture(path.c_str());
}

GLuint Material::CreateSolidColorTexture(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    unsigned char color[] = { r, g, b, a };
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}