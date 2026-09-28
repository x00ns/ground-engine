#include "Shapes.hpp"
#include "Colors.hpp"
#include <GL/glext.h>

void Shapes::drawRect(const Rect& rect, const std::function<void()>& children) {
    if (children) children();
}

void Shapes::drawTextureRect(const Rect& rect, const std::function<void()>& children) {
    if (children) children();
}

void Shapes::drawOval(const Oval& oval, const std::function<void()>& children) {
    if (children) children();
}

void Shapes::drawLine(const Line& line) {
    glUseProgram(shaderParam);
    // set color
    glUniform4f(glGetUniformLocation(shaderParam, "u_color"), line.col.r, line.col.g, line.col.b, line.col.a);
    // clear transforms
    glUniform2f(glGetUniformLocation(shaderParam, "u_translation"), 0.0f, 0.0f);
}
