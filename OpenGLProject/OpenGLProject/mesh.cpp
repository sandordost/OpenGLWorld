#include "mesh.h"
#include <iostream>
#include "defaultMaterial.h"

Mesh::Mesh() : Mesh::Mesh(DefaultMaterial()) {}

Mesh::Mesh(const Material& _material) : VAO(0), VBO(0), NBO(0), TBO(0), verticesCount(3), material(_material) {}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Mesh::SetupMesh(const std::vector<float>& vertices, const std::vector<float>& normals, const std::vector<float>& texCoords, const Material& material) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &NBO);
    GLuint TBO;
    glGenBuffers(1, &TBO);

    glBindVertexArray(VAO);

	this->material = material;

    // Vertex Buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Normal Buffer
    glBindBuffer(GL_ARRAY_BUFFER, NBO);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

	// Texture Buffer
    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(float), texCoords.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    verticesCount = vertices.size() / 3;
}

void Mesh::Draw(const Shader& shader, glm::mat4 modelTransform) const {
    glm::mat4 finalModel = modelTransform * transform;
    shader.SetMat4("model", finalModel);

    material.Bind(shader);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, verticesCount);
    glBindVertexArray(0);
}

void Mesh::Translate(const glm::vec3& translation) {
    transform = glm::translate(transform, translation);
}

void Mesh::Scale(const glm::vec3& scale) {
    transform = glm::scale(transform, scale);
}

void Mesh::Rotate(float angle, const glm::vec3& axis) {
    transform = glm::rotate(transform, glm::radians(angle), axis);
}