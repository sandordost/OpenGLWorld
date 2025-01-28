#include "mesh.h"
#include <iostream>

Mesh::Mesh() : VAO(0), VBO(0), NBO(0), verticesCount(3) {}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Mesh::SetupMesh(const std::vector<float>& vertices, const std::vector<float>& normals, const std::vector<float>& texCoords) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &NBO);
    GLuint TBO;
    glGenBuffers(1, &TBO); // UV Buffer

    glBindVertexArray(VAO);

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

    // Texture Coordinate Buffer (UV-coördinaten)
    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(float), texCoords.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    verticesCount = vertices.size() / 3;
}

void Mesh::Draw() const {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, verticesCount);
    glBindVertexArray(0);
}
