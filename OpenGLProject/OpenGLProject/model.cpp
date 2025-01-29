#include "Model.h"

void Model::AddMesh(const std::shared_ptr<Mesh>& mesh) {
    meshes.push_back(mesh);
}
void Model::Translate(const glm::vec3& translation) {
    transform = glm::translate(transform, translation);
}

void Model::Rotate(float angle, const glm::vec3& axis) {
    transform = glm::rotate(transform, glm::radians(angle), axis);
}

void Model::Scale(const glm::vec3& scale) {
    transform = glm::scale(transform, scale);
}

void Model::Draw(const Shader& shader) const {
    shader.SetMat4("model", transform);

    for (const auto& mesh : meshes) {
        mesh->Draw(shader, transform);
    }
}