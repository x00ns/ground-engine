#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
// vector 2
struct Vec2 { float x, y; };
// colors
struct Color {
    // constructor
    float r, g, b, a;
    Color(float r, float g, float b, float a) :
    r(r), g(g), b(b), a(a) {}
};
// texture
struct Texture2D { unsigned int texture_id = 0; };
// engine methods
class ground {
public:
    int width, height;
    const char* title;
    GLFWwindow* window = nullptr;
    bool Closed;

    ground(int width, int height, const char* title);
    ~ground();
    // functions
    void createWindow(int width, int height, const char* title);
    bool isClosed();
    void Update();
    void setBackgroundColor(const Color& color);
};
