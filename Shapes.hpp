#pragma once
#include "Engine.hpp"
#include <functional>
#include <GLFW/glfw3.h>
#include <GL/glcorearb.h>

#define GL_GLEXT_PROTOTYPES

struct Rect {
    float scaleX, scaleY;
    Vec2 pos;
    Color col;
    Texture2D texture;
    // constructor
    Rect(Vec2 position, float x, float y, Color color = {1.0f, 1.0f, 1.0f, 1.0f}) :
    pos(position), scaleX(x), scaleY(y), col(color), texture({}) {}
};

struct Oval {
    float radiusX, radiusY;
    Vec2 pos;
    Color col;
    Texture2D texture;
    // constructor
    Oval(Vec2 position, float x, float y, Color color = {1.0f, 1.0f, 1.0f, 1.0f}) :
    pos(position), radiusX(x), radiusY(y), col(color), texture({}) {}
};

struct Line {
    float x, y;
    Vec2 pos;
    Color col;
    //constructor
    Line(Vec2 position, float X, float Y, Color color = {1.0f, 1.0f, 1.0f, 1.0f}) :
    pos(position), x(X), y(Y), col(color) {}
};

class Shapes {
private:
    unsigned int shaderParam = 0;
    unsigned int quadVAO = 0, quadVBO = 0;
public:
    // constructor & destructor
    Shapes(int windowWidth, int windowHeight);
    ~Shapes();
    // create rects
    void drawRect(Vec2 pos, float scaleX, float scaleY, const Color& color, const std::function<void()>& children);
    void drawTextureRect(Vec2 pos, float scaleX, float scaleY, const Texture2D& texture, const std::function<void()>& children);
    // create ovals
    void drawOval(Vec2 pos, float scaleX, float scaleY, const Color& color, const std::function<void()>& children);
};
