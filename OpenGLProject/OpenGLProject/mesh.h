#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "material.h"
#include <memory>

class Scene;

class Mesh {
public:
    Mesh(const std::shared_ptr<Material>& _material);

    virtual ~Mesh();

    void SetupMesh(const std::vector<float>& vertices, const std::vector<float>& normals, const std::vector<float>& texCoords);
	void SetupMesh(const std::vector<float>& vertices, const std::vector<float>& normals, const std::vector<float>& texCoords, const std::vector<float>& tangents);

    void Draw(const std::shared_ptr<Scene>& scene, glm::mat4 modelTransform) const;

    void Translate(const glm::vec3& translation);
    void Scale(const glm::vec3& scale);
    void Rotate(float angle, const glm::vec3& axis);

    glm::mat4 GetTransform() const { return transform; }

protected:
    GLuint VAO, VBO, NBO, TBO;
    size_t verticesCount;
    std::shared_ptr<Material> material;

    glm::mat4 transform = glm::mat4(1.0f);
};
