#include "material.h"

Material::Material(const Shader& shader) : shader(shader) {}

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