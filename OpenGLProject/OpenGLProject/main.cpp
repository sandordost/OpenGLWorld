#include "Window.h"
#include "Shader.h"
#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "scene.h"
#include "mainScene.h"

void ProcessInput(GLFWwindow* window);
void MouseCallback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3(0.0f, 1.0f, 1.0f));
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float modelAngle = 0.0f;

int main() {
	Window window(1920, 1080, "Great OpenGL World");

	glfwSetCursorPosCallback(window.GetGLFWWindow(), MouseCallback);
	glfwSetKeyCallback(window.GetGLFWWindow(), key_callback);
	// lock mouse cursor
	glfwSetInputMode(window.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	auto mainScene = std::make_shared<MainScene>();
	mainScene->SetCamera(camera);

	while (!window.ShouldClose()) {
		window.Clear(0.1f, 0.1f, 0.1f, 1.0f);
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		ProcessInput(window.GetGLFWWindow());
		camera->Update(deltaTime);

		mainScene->Update();
		mainScene->Draw(deltaTime);

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}

static void ProcessInput(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		camera->MovementSpeed = 5.0f;
	else
		camera->MovementSpeed = 2.5f;

	if (camera->droneMode) {
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
			camera->ProcessKeyboard(UP, deltaTime);
		else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
			camera->ProcessKeyboard(DOWN, deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && camera->isGrounded) {
		camera->StartJump();
	}
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
		camera->toggleDroneMode();
}

static void MouseCallback(GLFWwindow* window, double xpos, double ypos) {
	static float lastX = 400, lastY = 300;
	static bool firstMouse = true;

	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	camera->ProcessMouseMovement(xoffset, yoffset);
}
