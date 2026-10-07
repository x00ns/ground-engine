#pragma once
#define GL_GLEXT_PROTOTYPES

#include "Engine.hpp"
#include <functional>
#include <GL/glcorearb.h>

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
    Vec2 point_1, point_2;
    Color col;
    //constructor
    Line(Vec2 Point_1, Vec2 Point_2, Color color = {1.0f, 1.0f, 1.0f, 1.0f}) :
    point_1(Point_1), point_2(Point_2), col(color) {}
};

class Shapes {
private:
    unsigned int shaderParam = 0;
    unsigned int quadVAO = 0, quadVBO = 0;
public:
    // constructor & destructor
    Shapes();
    ~Shapes();
    // create rects
    void drawRect(const Rect& rect, const std::function<void()>& children);
    void drawTextureRect(const Rect& rect, const std::function<void()>& children);
    // create ovals
    void drawOval(const Oval& oval, const std::function<void()>& children);
    // draw lines
    void drawLine(const Line& line);
};
