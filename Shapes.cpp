#include "Shapes.hpp"
#include "Colors.hpp"

Shapes::Shapes() {
    // rect & oval vao, vbo
    
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

    glBufferData(GL_ARRAY_BUFFER, 6 * 4 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // line vao, vbo

    glGenVertexArrays(1, &lineVAO);
    glGenBuffers(1, &lineVBO);
    
    glBindVertexArray(lineVAO);
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);

    glBufferData(GL_ARRAY_BUFFER, 2 * 2 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Shapes::drawRect(const Rect& rect, const std::function<void()>& children) {
    glUseProgram(shaderParam);
    // set color
    glUniform4f(glGetUniformLocation(shaderParam, "u_color"), rect.col.r, rect.col.g, rect.col.b, rect.col.a);
    // clear transforms
    glUniform2f(glGetUniformLocation(shaderParam, "u_translation"), 0.0f, 0.0f);

    float x1 = rect.pos.x;
    float y1 = rect.pos.y;
    float x2 = rect.pos.x + rect.scaleX;
    float y2 = rect.pos.y + rect.scaleY;
    
   float vertices[] = {
        x1, y1,  0.0f, 0.0f,
        x2, y1,  1.0f, 0.0f,
        x1, y2,  0.0f, 1.0f,

        x1, y2,  0.0f, 1.0f,
        x2, y1,  1.0f, 0.0f,
        x2, y2,  1.0f, 1.0f 
    };

    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindBuffer(0);
    glBindVertexArray(0);
    
    if (children) children();
}

void Shapes::drawTextureRect(const Rect& rect, const std::function<void()>& children) {
glUseProgram(shaderParam);
    // set texture
    glUniform1i(glGetUniformLocation(shaderProgram, "u_use_texture"), 1);
    // clear transforms
    glUniform2f(glGetUniformLocation(shaderParam, "u_translation"), 0.0f, 0.0f);

    float x1 = rect.pos.x;
    float y1 = rect.pos.y;
    float x2 = rect.pos.x + rect.scaleX;
    float y2 = rect.pos.y + rect.scaleY;
    
   float vertices[] = {
        x1, y1,  0.0f, 0.0f,
        x2, y1,  1.0f, 0.0f,
        x1, y2,  0.0f, 1.0f,

        x1, y2,  0.0f, 1.0f,
        x2, y1,  1.0f, 0.0f,
        x2, y2,  1.0f, 1.0f 
    };

    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

    glBindTexture(GL_TEXTURE_2D, rect.texture.texture_id);
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(0);
    glBindVertexArray(0);
    
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

    glBindVertexArray(lineVAO);
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    
    glDrawArrays(GL_LINES, 0, 2);
    glBindBuffer(0);
    glBindVertexArray(0);
}
