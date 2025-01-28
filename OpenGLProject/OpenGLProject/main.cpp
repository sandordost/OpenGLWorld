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

void ProcessInput(GLFWwindow* window);
void MouseCallback(GLFWwindow* window, double xpos, double ypos);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float modelAngle = 0.0f;

int main() {
    Window window(800, 600, "OpenGL Minimal Triangle");

    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");

    // 🔥 Maak dynamische vormen aan
    auto square = std::make_shared<SquareMesh>();
    auto triangle = std::make_shared<TriangleMesh>();
	auto cube = std::make_shared<CubeMesh>();

	auto model = std::make_shared<Model>();
	model->AddMesh(cube);

	auto model2 = std::make_shared<Model>();
	model2->AddMesh(triangle);

    model2->Translate(glm::vec3(0.0f, 0.0f, -3.0f));

    glfwSetCursorPosCallback(window.GetGLFWWindow(), MouseCallback);

    while (!window.ShouldClose()) {
        ProcessInput(window.GetGLFWWindow());

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        window.Clear(0.1f, 0.1f, 0.1f, 1.0f);

        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        shader.Use();

        shader.SetMat4("view", view);
        shader.SetMat4("projection", projection);
        
		model->Rotate(modelAngle, glm::vec3(0.0f, 0.0f, -1));
		model->Draw(shader);
		model2->Draw(shader);

        window.SwapBuffers();
        window.PollEvents();

		modelAngle += 0.1 * deltaTime;
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
