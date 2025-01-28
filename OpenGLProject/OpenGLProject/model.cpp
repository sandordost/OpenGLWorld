#include "Model.h"

void Model::AddMesh(const std::shared_ptr<Mesh>& mesh) {
    meshes.push_back(mesh);
}
void Model::Translate(const glm::vec3& translation) {
    modelMatrix = glm::translate(modelMatrix, translation);
}

void Model::Rotate(float angle, const glm::vec3& axis) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), axis);
}

void Model::Scale(const glm::vec3& scale) {
    modelMatrix = glm::scale(modelMatrix, scale);
}

void Model::Draw(const Shader& shader) const {
    shader.SetMat4("model", modelMatrix);

    for (const auto& mesh : meshes) {
        mesh->Draw();
    }
}