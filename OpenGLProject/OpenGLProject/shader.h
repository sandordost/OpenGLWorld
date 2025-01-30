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

	void SetLightPos(const glm::vec3& lightPos) const;
	void SetLightColor(const glm::vec3& lightColor) const;
	void SetViewPos(const glm::vec3& viewPos) const;
	void SetView(const glm::mat4& view) const;
	void SetProjection(const glm::mat4& projection) const;
	void SetModel(const glm::mat4& model) const;

	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetBool(const std::string& name, bool value) const;
};

