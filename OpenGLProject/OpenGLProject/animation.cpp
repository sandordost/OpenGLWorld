#define GLM_ENABLE_EXPERIMENTAL
#include "Animation.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <algorithm>
#include "sceneObject.h"

Animation::Animation(const std::shared_ptr<SceneObject>& sceneObj)
    : sceneObject(sceneObj) {
}

Animation::~Animation() {}

void Animation::AddKeyframe(float time, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) {
    keyframes.emplace_back(time, position, rotation, scale);
    std::sort(keyframes.begin(), keyframes.end(), [](const AnimationKeyframe& a, const AnimationKeyframe& b) {
        return a.time < b.time;
        });
}

void Animation::Update(float dt) {
    if (keyframes.empty()) return;

    time += dt;

    if (loop && time > keyframes.back().time) {
        time = std::fmod(time, keyframes.back().time);
    }
    else if (!loop && time > keyframes.back().time) {
        time = keyframes.back().time;
    }

    AnimationKeyframe* currentFrame = nullptr;
    AnimationKeyframe* nextFrame = nullptr;

    for (size_t i = 0; i < keyframes.size() - 1; i++) {
        if (time >= keyframes[i].time && time <= keyframes[i + 1].time) {
            currentFrame = &keyframes[i];
            nextFrame = &keyframes[i + 1];
            break;
        }
    }

    if (currentFrame && nextFrame) {
        float progress = (time - currentFrame->time) / (nextFrame->time - currentFrame->time);
        InterpolateTransform(progress, *currentFrame, *nextFrame);
    }
}

void Animation::InterpolateTransform(float t, const AnimationKeyframe& current, const AnimationKeyframe& next) {
    // Interpoleer positie en schaal lineair
    glm::vec3 interpolatedPosition = glm::mix(current.position, next.position, t);
    glm::vec3 interpolatedScale = glm::mix(current.scale, next.scale, t);

    // Interpoleer rotatie met slerp via quaternions
    glm::quat currentRotation = glm::quat(glm::radians(current.rotation));
    glm::quat nextRotation = glm::quat(glm::radians(next.rotation));
    glm::quat interpolatedRotation = glm::slerp(currentRotation, nextRotation, t);

    // Pas transformatie toe op het SceneObject
    sceneObject->SetTransform(interpolatedPosition, interpolatedRotation, interpolatedScale);
}
