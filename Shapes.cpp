#include "Shapes.hpp"
#include "Colors.hpp"

Shapes::Shapes() {
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

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
    // create vertices
    float vertices[] = {
        line.point_1.x, line.point_1.y,
        line.point_2.x, line.point_2.y
    };
    
    glDrawArrays(GL_LINES, 0, 2);
    glBindBuffer(0);
    glBindVertexArray(0);
}
