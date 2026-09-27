#include "Engine.hpp"

int main() {
    ground window(800, 600, "OpenGL");

    while (!window.isClosed()) {
        window.Update();
    }

    return 0;
}
