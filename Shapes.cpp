#include "Shapes.hpp"
#include "Colors.hpp"

Shapes::Shapes() {
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

    glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
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

    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    
    glDrawArrays(GL_LINES, 0, 2);
    glBindBuffer(0);
    glBindVertexArray(0);
}
