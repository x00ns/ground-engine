#include "Colors.hpp"
#include "Engine.hpp"

int main() {
    ground window(800, 600, "OpenGL");

    window.setBackgroundColor(LIGHTBLUE);

    while (!window.isClosed()) {
        window.Update();
    }

    return 0;
}
