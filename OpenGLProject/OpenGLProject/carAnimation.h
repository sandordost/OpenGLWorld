#pragma once
#include "sceneObject.h"
#include "animation.h"

class CarAnimation : public Animation {
public:
	CarAnimation(const std::shared_ptr<SceneObject>& carObject) : Animation(carObject) {
		// Set up keyframes
		glm::vec3 scale = carObject->GetScale();
		glm::vec3 startRotation = carObject->GetRotationInDegrees();
		glm::vec3 startPosition = carObject->GetPosition();

		// Drive forward
		keyframes.push_back(AnimationKeyframe(0, startPosition + glm::vec3(0,0,0), startRotation + glm::vec3(0,0,0), scale));
		keyframes.push_back(AnimationKeyframe(2.5f, startPosition + glm::vec3(14, 0, 0), startRotation + glm::vec3(0, 0, 0), scale));
		// Start turning right
		keyframes.push_back(AnimationKeyframe(3, startPosition + glm::vec3(16, 0, 0), startRotation + glm::vec3(0, -90, 0), scale));

		// Drive forward
		keyframes.push_back(AnimationKeyframe(3, startPosition + glm::vec3(16, 0, 0), startRotation + glm::vec3(0, -90, 0), scale));
		keyframes.push_back(AnimationKeyframe(5.5f, startPosition + glm::vec3(16, 0, 14), startRotation + glm::vec3(0, -90, 0), scale));
		// Start turning right
		keyframes.push_back(AnimationKeyframe(6, startPosition + glm::vec3(16, 0, 16), startRotation + glm::vec3(0, -180, 0), scale));

		// Drive forward
		keyframes.push_back(AnimationKeyframe(6, startPosition + glm::vec3(16, 0, 16), startRotation + glm::vec3(0, -180, 0), scale));
		keyframes.push_back(AnimationKeyframe(8.5f, startPosition + glm::vec3(2, 0, 16), startRotation + glm::vec3(0, -180, 0), scale));
		// Start turning right
		keyframes.push_back(AnimationKeyframe(9, startPosition + glm::vec3(0, 0, 16), startRotation + glm::vec3(0, -270, 0), scale));

		// Drive forward
		keyframes.push_back(AnimationKeyframe(9, startPosition + glm::vec3(0, 0, 16), startRotation + glm::vec3(0, -270, 0), scale));
		keyframes.push_back(AnimationKeyframe(11.5f, startPosition + glm::vec3(0, 0, 2), startRotation + glm::vec3(0, -270, 0), scale));
		// Start turning right
		keyframes.push_back(AnimationKeyframe(12, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 0, 0), scale));

	}
};