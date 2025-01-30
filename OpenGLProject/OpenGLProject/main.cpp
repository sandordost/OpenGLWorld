#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "squareMesh.h"
#include "triangleMesh.h"
#include "cubeMesh.h"
#include "sceneObject.h"
#include "houseObject.h"
#include "pyramidMesh.h"
#include "sandMaterial.h"
#include "objectLoader.h"
#include "airplane.h"
#include "lantern.h"
#include "scene.h"
#include "matteMaterial.h"

void ProcessInput(GLFWwindow* window);
void MouseCallback(GLFWwindow* window, double xpos, double ypos);

std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3(0.0f, 0.0f, 1.0f));
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float modelAngle = 0.0f;

int main() {
	Window window(1920, 1080, "Great OpenGL World");

	glfwSetCursorPosCallback(window.GetGLFWWindow(), MouseCallback);
	// lock mouse cursor
	glfwSetInputMode(window.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	Scene scene = Scene();
	scene.SetCamera(camera);

	//Test meshes
	auto sceneObject = std::make_shared<SceneObject>();
	auto sandMaterial = std::make_shared<MatteMaterial>(255,0,0,255);
	auto square = std::make_shared<SquareMesh>(sandMaterial);
	auto triangle = std::make_shared<TriangleMesh>(sandMaterial);
	auto cube = std::make_shared<CubeMesh>(sandMaterial);
	sceneObject->AddMesh(square);
	sceneObject->AddMesh(triangle);
	sceneObject->AddMesh(cube);
	scene.AddObject(sceneObject);
	sceneObject->Translate(glm::vec3(0.0f, 0.0f, -2.0f));

	auto house = std::make_shared<HouseObject>();
	house->Translate(glm::vec3(1.5f, 0.0f, -2.0f));
	scene.AddObject(house);

	auto airplane = std::make_shared<AirPlaneObject>();
	airplane->Scale(glm::vec3(0.1f, 0.1f, 0.1f));
	airplane->Translate(glm::vec3(0, 2.0f, 0));
	scene.AddObject(airplane);

	while (!window.ShouldClose()) {
		ProcessInput(window.GetGLFWWindow());

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		window.Clear(0.1f, 0.1f, 0.1f, 1.0f);

		scene.Update();
		scene.Draw();

		sceneObject->Rotate(0.4f, glm::vec3(0.0f, 0.0f, -1));

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}

static void ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->ProcessKeyboard(RIGHT, deltaTime);
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
