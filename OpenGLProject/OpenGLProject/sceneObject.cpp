#include "sceneObject.h"
#include "scene.h"
#include <glm/gtx/quaternion.hpp>

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

void SceneObject::Draw(const std::shared_ptr<Scene>& scene) {

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

void SceneObject::SetTransform(const glm::vec3& position, const glm::quat& rotation, const glm::vec3& scale) {
	transform = glm::translate(glm::mat4(1.0f), position);

	transform *= glm::toMat4(rotation);

	transform = glm::scale(transform, scale);
}

// Solution found on https://stackoverflow.com/questions/15022630/how-to-calculate-the-angle-from-rotation-matrix
glm::vec3 SceneObject::GetRotationInDegrees() const {
	glm::vec3 euler{};

	// Yaw (Y-as)
	euler.y = glm::degrees(atan2(transform[0][2], transform[2][2]));

	// Pitch (X-as)
	float sinPitch = -transform[1][2];
	if (sinPitch <= -1.0f) sinPitch = -1.0f;
	else if (sinPitch >= 1.0f) sinPitch = 1.0f;
	euler.x = glm::degrees(asin(sinPitch));

	// Roll (Z-as)
	euler.z = glm::degrees(atan2(transform[1][0], transform[1][1]));

	return euler;
}