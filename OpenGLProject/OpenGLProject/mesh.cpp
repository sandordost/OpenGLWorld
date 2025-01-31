#include "mesh.h"
#include <iostream>
#include "scene.h"

Mesh::Mesh(const std::shared_ptr<Material>& _material) : VAO(0), VBO(0), NBO(0), TBO(0), TanBO(0), verticesCount(3), material(_material) {}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Mesh::SetupMesh(const std::vector<float>& vertices, const std::vector<float>& normals, const std::vector<float>& texCoords) {
    // Bereken de tangents
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &NBO);
    glGenBuffers(1, &TBO);
	glGenBuffers(1, &TanBO);

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

    // Texture Buffer
    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(float), texCoords.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);

	// Tangent Buffer
    std::vector<float> tangents;
    CalculateTangents(vertices, texCoords, tangents);
    glBindBuffer(GL_ARRAY_BUFFER, TanBO);
    glBufferData(GL_ARRAY_BUFFER, tangents.size() * sizeof(float), tangents.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(3);

    std::cout << "Mesh setup met " << vertices.size() / 3
        << " vertices, " << normals.size() / 3
        << " normals, " << texCoords.size() / 2
        << " texCoords, " << tangents.size() / 3
        << " tangents.\n";

    verticesCount = vertices.size() / 3;
}

void Mesh::Draw(const std::shared_ptr<Scene>& scene, glm::mat4 modelTransform) const {
    glm::mat4 finalModel = modelTransform * transform;
	Shader shader = material->GetShader();

	shader.Use();

    shader.SetView(scene->GetViewMatrix());
	shader.SetViewPos(scene->GetCameraPosition());
    shader.SetProjection(scene->GetProjectionMatrix());
    shader.SetModel(finalModel);

	shader.SetLightPos(scene->GetLightPosition());
	shader.SetLightColor(scene->GetLightColor());

    material->Bind();

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

void Mesh::CalculateTangents(const std::vector<float>& vertices, const std::vector<float>& texCoords, std::vector<float>& tangents) {
    for (size_t i = 0; i < vertices.size(); i += 9) {
        glm::vec3 pos1(vertices[i], vertices[i + 1], vertices[i + 2]);
        glm::vec3 pos2(vertices[i + 3], vertices[i + 4], vertices[i + 5]);
        glm::vec3 pos3(vertices[i + 6], vertices[i + 7], vertices[i + 8]);

        glm::vec2 uv1(texCoords[(i / 3) * 2], texCoords[(i / 3) * 2 + 1]);
        glm::vec2 uv2(texCoords[(i / 3 + 1) * 2], texCoords[(i / 3 + 1) * 2 + 1]);
        glm::vec2 uv3(texCoords[(i / 3 + 2) * 2], texCoords[(i / 3 + 2) * 2 + 1]);

        glm::vec3 deltaPos1 = pos2 - pos1;
        glm::vec3 deltaPos2 = pos3 - pos1;
        glm::vec2 deltaUV1 = uv2 - uv1;
        glm::vec2 deltaUV2 = uv3 - uv1;

        float f = deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y;
        if (fabs(f) < 1e-6) {
            f = 1.0f; // Vermijd deling door 0
        }
        else {
            f = 1.0f / f;
        }

        glm::vec3 tangent;
        tangent.x = f * (deltaUV2.y * deltaPos1.x - deltaUV1.y * deltaPos2.x);
        tangent.y = f * (deltaUV2.y * deltaPos1.y - deltaUV1.y * deltaPos2.y);
        tangent.z = f * (deltaUV2.y * deltaPos1.z - deltaUV1.y * deltaPos2.z);
        tangent = glm::normalize(tangent);

        // Voeg tangent toe voor alle drie vertices
        for (int j = 0; j < 3; j++) {
            tangents.push_back(tangent.x);
            tangents.push_back(tangent.y);
            tangents.push_back(tangent.z);
        }
    }
}