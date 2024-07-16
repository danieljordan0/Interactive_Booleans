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
    andGate.sprite.setScale(0.5, 0.5);

    SwitchComponent topSwitch("Switch 1", Vector2f(0, 200));
    topSwitch.circle.setFillColor(blueColor);

    SwitchComponent bottomSwitch("Switch 1", Vector2f(0, 800 - 250));
    bottomSwitch.circle.setFillColor(blueColor);

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
            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                SwitchComponent *switches[] = {&topSwitch, &bottomSwitch};

                for (SwitchComponent *sw : switches)
                {
                    if (sw->isClicked(mousePos))
                    {
                        sw->circle.setFillColor(sw->circle.getFillColor() == blueColor ? greenColor : blueColor);
                        break;
                    }
                }
                if (andGate.IsClicked(mousePos))
                {
                    // Add dragging logic
                }
            }
        }

        window.clear(greyColor);

        window.draw(topSwitch.circle);
        window.draw(bottomSwitch.circle);
        window.draw(andGate.sprite);

        window.display();
    }

    return 0;
}
