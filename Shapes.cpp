#include "Shapes.hpp"

void Shapes::drawRect(Vec2 pos, float scaleX, float scaleY, const Color& color, const std::function<void()>& children) {
    if (children) children();
}

void Shapes::drawTextureRect(Vec2 pos, float scaleX, float scaleY, const Texture2D& texture, const std::function<void()>& children) {
    if (children) children();
}

void Shapes::drawOval(Vec2 pos, float scaleX, float scaleY, const Color& color, const std::function<void()>& children) {
    if (children) children();
}
