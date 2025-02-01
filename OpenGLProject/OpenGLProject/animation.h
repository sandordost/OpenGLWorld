#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <memory>

class SceneObject;
class AnimationKeyframe;

class Animation
{
public:
	Animation(const std::shared_ptr<SceneObject>& sceneObj);
	~Animation();

	void AddKeyframe(float time, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale);
	void Update(float dt);

protected:
	std::vector<AnimationKeyframe> keyframes;

private:
	void InterpolateTransform(float t, const AnimationKeyframe& current, const AnimationKeyframe& next);
	std::shared_ptr<SceneObject> sceneObject;
	float time = 0.0f;
	bool loop = true;
};

class AnimationKeyframe {
public:
	AnimationKeyframe(float time, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
		: time(time), position(position), rotation(rotation), scale(scale) {
	}

	float time;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};
