#include "Engine.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

ground::~ground() {
    if (window) {
        glfwDestroyWindow(window);
    }

    glfwTerminate();
}

ground::ground(int width, int height, const char* title) :
width(width), height(height), title(title), window(nullptr), Closed(false) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        Closed = true;
        return;
    }

    createWindow(width, height, title);
}

void ground::createWindow(int width, int height, const char* title) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        Closed = true;
        return;
    }
    // glfw context
    glfwMakeContextCurrent(window);
}

bool ground::isClosed() {
    if (Closed) return true;

    if (glfwWindowShouldClose(window)) {
        Closed = true;
    }
    return Closed;
}

void ground::setBackgroundColor(const Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void ground::Update() {
    if (!window) return;
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}
