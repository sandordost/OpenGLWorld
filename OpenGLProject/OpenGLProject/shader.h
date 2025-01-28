#pragma once
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
    GLuint ID;
    Shader(const char* vertexPath, const char* fragmentPath);
    void Use() const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, glm::vec3 vec3) const;
    void SetMat4(const std::string& name, glm::mat4) const;
	void SetInt(const std::string& name, int value) const;
};

