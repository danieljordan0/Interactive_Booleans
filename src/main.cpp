#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Gate.h"
#include "AndGate.h"
#include "Switch.h"
#include <spdlog/spdlog.h>
#include <iostream>
#include <colors.h>

using namespace sf;

int main()
{

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(sf::VideoMode(1200, 800), "Boolean", Style::Default, settings);

    AndGate andGate;

    SwitchComponent switchComponent("Switch 1", Vector2f(0, 200));
    switchComponent.circle.setFillColor(blueColor);


    // Main loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (switchComponent.isClicked(mousePos))
                    {
                        if (switchComponent.circle.getFillColor() == blueColor)
                        {
                            switchComponent.circle.setFillColor(greenColor);
                        }
                        else
                        {
                            switchComponent.circle.setFillColor(blueColor);
                        }
                    }
                }
            }
        }

        // Clear the window with the background color
        window.clear(greyColor);

        window.draw(switchComponent.circle);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
