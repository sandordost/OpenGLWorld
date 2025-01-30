#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "objLoader.h"
#include "mesh.h"

class SceneObject {
public:
	SceneObject() : transform(1.0f) {}

    void Translate(const glm::vec3& translation);
    void Rotate(float angle, const glm::vec3& axis);
    void Scale(const glm::vec3& scale);

    void AddMesh(const std::shared_ptr<Mesh>& mesh);
    void Draw(const std::shared_ptr<Scene>& scene);
	void CreateFromOBJ(const std::string& path, const std::shared_ptr<Material>& mat);

private:
    std::vector<std::shared_ptr<Mesh>> meshes;
    glm::mat4 transform;
};
