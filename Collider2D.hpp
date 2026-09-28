#pragma once
#include "Engine.hpp"

struct RectCollision {
    bool enabled, isDynamic;
    Vec2 pos;
    float scaleX, scaleY;
    // constructor
    RectCollision(bool enabled, Vec2 position, float X, float Y, bool isDynamic) :
    enabled(enabled), pos(position), scaleX(X), scaleY(Y), isDynamic(isDynamic) {}
};

struct OvalCollision {
    bool enabled, isDynamic;
    Vec2 pos;
    float scaleX, scaleY;
    // constructor
    OvalCollision(Vec2 position, float X, float Y) :
    pos(position), scaleX(X), scaleY(Y) {}
};
