#include "sceneObject.h"
#include "scene.h"

void SceneObject::AddMesh(const std::shared_ptr<Mesh>& mesh) {
	meshes.push_back(mesh);
}
void SceneObject::Translate(const glm::vec3& translation) {
    transform = glm::translate(transform, translation);
}

void SceneObject::Rotate(float angle, const glm::vec3& axis) {
    transform = glm::rotate(transform, glm::radians(angle), axis);
}

void SceneObject::Scale(const glm::vec3& scale) {
    transform = glm::scale(transform, scale);
}

void SceneObject::Draw(const std::shared_ptr<Scene>& scene){

    for (const auto& mesh : meshes) {
        mesh->Draw(scene, transform);
    }
}

void SceneObject::CreateFromOBJ(const std::string& path, const std::shared_ptr<Material>& mat)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	OBJLoader::loadOBJ(path, vertices, uvs, normals);

	std::vector<float> verticesFloat;
	std::vector<float> normalsFloat;
	std::vector<float> uvsFloat;

	for (size_t i = 0; i < vertices.size(); i++) {
		verticesFloat.push_back(vertices[i].x);
		verticesFloat.push_back(vertices[i].y);
		verticesFloat.push_back(vertices[i].z);
	}

	for (size_t i = 0; i < normals.size(); i++) {
		normalsFloat.push_back(normals[i].x);
		normalsFloat.push_back(normals[i].y);
		normalsFloat.push_back(normals[i].z);
	}

	for (size_t i = 0; i < uvs.size(); i++) {
		uvsFloat.push_back(uvs[i].x);
		uvsFloat.push_back(uvs[i].y);
	}

	auto mesh = std::make_shared<Mesh>(mat);

	mesh->SetupMesh(verticesFloat, normalsFloat, uvsFloat);

	AddMesh(mesh);
}
