#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "objLoader.h"
#include "mesh.h"
#include "animation.h"

class SceneObject {
public:
	SceneObject() : transform(1.0f) {}

    void Translate(const glm::vec3& translation);
    void Rotate(float angle, const glm::vec3& axis);
    void Scale(const glm::vec3& scale);

    void AddMesh(const std::shared_ptr<Mesh>& mesh);
    void Draw(const std::shared_ptr<Scene>& scene);
	void CreateFromOBJ(const std::string& path, const std::shared_ptr<Material>& mat);
	void SetTransform(const glm::vec3& position, const glm::quat& rotation, const glm::vec3& scale);
	void SetAnimation(const std::shared_ptr<Animation>& animation) { currentAnimation = animation; }
	void Animate(float deltaTime) { if (currentAnimation) currentAnimation->Update(deltaTime); }

private:
	std::shared_ptr<Animation> currentAnimation;
    std::vector<std::shared_ptr<Mesh>> meshes;
    glm::mat4 transform;
};
