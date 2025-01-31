#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(2.5f), MouseSensitivity(0.1f), Zoom(45.0f) {
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
	fixedY = position.y;
    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;

	float startY = Position.y;

    if (direction == FORWARD)
        Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
	if (direction == UP)
		Position += Up * velocity;
	if (direction == DOWN)
		Position -= Up * velocity;

    if(!droneMode) Position.y = startY;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch) {
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (constrainPitch) {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    UpdateCameraVectors();
}

void Camera::Update(float deltaTime)
{
    if (isJumping) {
        verticalVelocity += gravity * deltaTime;
        Position.y += verticalVelocity * deltaTime;

        if (verticalVelocity <= 0.0f) {
            isJumping = false;
        }
    }
    else if (!isGrounded) {
        verticalVelocity += gravity * deltaTime;
        Position.y += verticalVelocity * deltaTime;

        if (Position.y <= fixedY) {
            Position.y = fixedY;
            verticalVelocity = 0.0f;
            isGrounded = true;
        }
    }
}

void Camera::toggleDroneMode()
{
	droneMode = !droneMode;

	if (!droneMode) {
		Position.y = fixedY;
		isGrounded = true;
		isJumping = false;
	}
}

void Camera::StartJump() {
    if (isGrounded && !droneMode) {
        isJumping = true;
        isGrounded = false;
        verticalVelocity = initialJumpVelocity;  // Start sprong met initiële kracht
    }
}

void Camera::UpdateCameraVectors() {
    glm::vec3 front{};
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);

    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}
