#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool ShouldClose() const;
    void SwapBuffers();
    void PollEvents();
    void Clear(float r, float g, float b, float a);
    GLFWwindow* GetGLFWWindow() const;

private:
    GLFWwindow* window;
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
