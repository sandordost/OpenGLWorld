#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "squareMesh.h"
#include "triangleMesh.h"
#include "cubeMesh.h"
#include "model.h"
#include "houseModel.h"
#include "pyramidMesh.h"
#include "defaultMaterial.h"
#include "sandMaterial.h"
#include "objectLoader.h"
#include "airplane.h"

void ProcessInput(GLFWwindow* window);
void MouseCallback(GLFWwindow* window, double xpos, double ypos);

Camera camera(glm::vec3(0.0f, 0.0f, 1.0f));
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float modelAngle = 0.0f;

int main() {
    Window window(800, 600, "OpenGL Minimal Triangle");

    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");

    // 🔥 Maak dynamische vormen aan
    auto square = std::make_shared<SquareMesh>(DefaultMaterial());
    auto triangle = std::make_shared<TriangleMesh>(DefaultMaterial());
	auto cube = std::make_shared<CubeMesh>(DefaultMaterial());

    auto airPlane = AirPlaneModel();
	airPlane.Translate(glm::vec3(0.0f, 0.0f, 0.0f));

	auto model = std::make_shared<Model>();
	model->AddMesh(cube);

    // Create sand plane
	Model sandPlaneModel;
    auto sandPlane = std::make_shared<SquareMesh>(SandMaterial());
	sandPlane->Scale(glm::vec3(10.0f, 10.0f, 10.0f));
	sandPlane->Rotate(-90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	sandPlane->Translate(glm::vec3(0.0f, -1.0f, 0.0f));
	sandPlaneModel.AddMesh(sandPlane);

	auto model2 = std::make_shared<Model>();
	model2->AddMesh(triangle);

    model2->Translate(glm::vec3(0.0f, 0.0f, -3.0f));

	HouseModel houseModel;
	houseModel.Scale(glm::vec3(2.0f, 2.0f, 2.0f));
	houseModel.Translate(glm::vec3(1.0f, 0.5f, 5.0f));
    
    PyramidMesh piramidMesh = PyramidMesh(DefaultMaterial());
    piramidMesh.Translate(glm::vec3(-1.0f, 0.0f, 0));

    glfwSetCursorPosCallback(window.GetGLFWWindow(), MouseCallback);
	// lock mouse cursor
	glfwSetInputMode(window.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    while (!window.ShouldClose()) {
        ProcessInput(window.GetGLFWWindow());

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        window.Clear(0.1f, 0.1f, 0.1f, 1.0f);

        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(60.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        shader.Use();

        // Lichtinstellingen
        shader.SetVec3("lightPos", glm::vec3(0, 4.0f,3.0f)); // Positie van het licht
        shader.SetVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f)); // Witte kleur licht
        shader.SetVec3("viewPos", camera.Position);

        shader.SetMat4("view", view);
        shader.SetMat4("projection", projection);
        
		model->Rotate(0.4f, glm::vec3(0.0f, 0.0f, -1));
		model2->Rotate(0.4f, glm::vec3(0.0f, 1.0f, 0.0f));
		model->Draw(shader);
		model2->Draw(shader);
		houseModel.Draw(shader);
		sandPlaneModel.Draw(shader);
		airPlane.Draw(shader);

		piramidMesh.Draw(shader, glm::mat4(1.0f));

        window.SwapBuffers();
        window.PollEvents();
    }

    return 0;
}

static void ProcessInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
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

    camera.ProcessMouseMovement(xoffset, yoffset);
}
