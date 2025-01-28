#pragma once
#include <vector>
#include <memory>
#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"

class Model {
public:
	Model() : modelMatrix(1.0f) {}

    void Translate(const glm::vec3& translation);
    void Rotate(float angle, const glm::vec3& axis);
    void Scale(const glm::vec3& scale);

    void AddMesh(const std::shared_ptr<Mesh>& mesh);
    void Draw(const Shader& shader) const;

private:
    std::vector<std::shared_ptr<Mesh>> meshes;
    glm::mat4 modelMatrix;
};
