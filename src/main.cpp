#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
#include <string>
#include "Gate.h"
#include "AndGate.h"
#include <spdlog/spdlog.h>
#include <iostream>

using namespace sf;

int main() {
    // Create a window
    RenderWindow window(VideoMode(1280, 832), "SFML Window");

    // Set the background color
    Color bgColour(255, 255, 255);

    AndGate andGate;

    // Variables to track dragging state
    bool isDragging = false;
    Vector2f offset;

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Clear the window with the background color
        window.clear(bgColour);

        // Ensure gates contain at least one entry
        window.draw(andGate.sprite);


        // Display the contents of the window
        window.display();
    }

    return 0;
}
