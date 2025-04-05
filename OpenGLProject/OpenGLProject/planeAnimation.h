#pragma once
#include "sceneObject.h"
#include "animation.h"

class PlaneAnimation : public Animation {
public:
	PlaneAnimation(const std::shared_ptr<SceneObject>& planeObject) : Animation(planeObject) {
		// Set up keyframes
		glm::vec3 scale = planeObject->GetScale();
		glm::vec3 startRotation = planeObject->GetRotationInDegrees();
		glm::vec3 startPosition = planeObject->GetPosition();

		// Make up a nice flying path in the sky (can be randomly made, but should return to the start position)
		keyframes.push_back(AnimationKeyframe(0, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 0, 0), scale));
		keyframes.push_back(AnimationKeyframe(2.5f, startPosition + glm::vec3(0, 0, 10), startRotation + glm::vec3(0, 0, 0), scale));
		keyframes.push_back(AnimationKeyframe(5.0f, startPosition + glm::vec3(10, 0, 10), startRotation + glm::vec3(0, 45, 0), scale));
		keyframes.push_back(AnimationKeyframe(7.5f, startPosition + glm::vec3(10, 0, 0), startRotation + glm::vec3(0, 90, 0), scale));
		keyframes.push_back(AnimationKeyframe(10.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 135, 0), scale));
		keyframes.push_back(AnimationKeyframe(12.5f, startPosition + glm::vec3(-10, 0, 0), startRotation + glm::vec3(0, 180, 0), scale));
		keyframes.push_back(AnimationKeyframe(15.0f, startPosition + glm::vec3(-10, 0, -10), startRotation + glm::vec3(0, 225, 0), scale));
		keyframes.push_back(AnimationKeyframe(17.5f, startPosition + glm::vec3(0, 0, -10), startRotation + glm::vec3(0, 270, 0), scale));
		keyframes.push_back(AnimationKeyframe(20.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 315, 0), scale));
		keyframes.push_back(AnimationKeyframe(22.5f, startPosition + glm::vec3(0, 0, 10), startRotation + glm::vec3(0, 360, 0), scale));
		keyframes.push_back(AnimationKeyframe(25.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 405, 0), scale));
		keyframes.push_back(AnimationKeyframe(27.5f, startPosition + glm::vec3(0, 0, -10), startRotation + glm::vec3(0, 450, 0), scale));
		keyframes.push_back(AnimationKeyframe(30.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 495, 0), scale));
		keyframes.push_back(AnimationKeyframe(32.5f, startPosition + glm::vec3(0, 0, 10), startRotation + glm::vec3(0, 540, 0), scale));
		keyframes.push_back(AnimationKeyframe(35.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 585, 0), scale));
		keyframes.push_back(AnimationKeyframe(37.5f, startPosition + glm::vec3(0, 0, -10), startRotation + glm::vec3(0, 630, 0), scale));
		keyframes.push_back(AnimationKeyframe(40.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 675, 0), scale));
		keyframes.push_back(AnimationKeyframe(42.5f, startPosition + glm::vec3(0, 0, 10), startRotation + glm::vec3(0, 720, 0), scale));
		keyframes.push_back(AnimationKeyframe(45.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 765, 0), scale));
		keyframes.push_back(AnimationKeyframe(47.5f, startPosition + glm::vec3(0, 0, -10), startRotation + glm::vec3(0, 810, 0), scale));
		keyframes.push_back(AnimationKeyframe(50.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 855, 0), scale));
		keyframes.push_back(AnimationKeyframe(52.5f, startPosition + glm::vec3(0, 0, 10), startRotation + glm::vec3(0, 900, 0), scale));
		keyframes.push_back(AnimationKeyframe(55.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 945, 0), scale));
		keyframes.push_back(AnimationKeyframe(57.5f, startPosition + glm::vec3(0, 0, -10), startRotation + glm::vec3(0, 990, 0), scale));
		keyframes.push_back(AnimationKeyframe(60.0f, startPosition + glm::vec3(0, 0, 0), startRotation + glm::vec3(0, 1035, 0), scale));

	}
};