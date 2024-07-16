#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Gate.h"
#include "AndGate.h"
#include "Switch.h"
#include <spdlog/spdlog.h>
#include <iostream>
#include <colors.h>
#include <vector>
#include <memory>
#include <bulb.h>

using namespace sf;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1200, 800), "Boolean", Style::Default, settings);

    std::vector<std::unique_ptr<Component>> gates;
    std::vector<std::unique_ptr<Bulb>> bulbs;

    // Create Switches
    SwitchComponent topSwitch("Switch 1", Vector2f(0, 200));
    topSwitch.circle.setFillColor(blueColor);

    SwitchComponent bottomSwitch("Switch 1", Vector2f(0, 800 - 250));
    bottomSwitch.circle.setFillColor(blueColor);

    // Create AND Gate
    auto andGate = std::make_unique<AndGate>();
    andGate->sprite.setPosition(0, 200);
    gates.push_back(std::move(andGate));

    auto bulb = std::make_unique<Bulb>("Bulb", Vector2f(400, 400));
    bulb->circle.setFillColor(greyColor);
    bulbs.push_back(std::move(bulb));

    bool isDragging = false;
    Component *selectedComponent = nullptr;
    Vector2f dragOffset;

    // FPS calculation
    Clock clock;
    Time elapsedTime;
    int frameCount = 0;
    float fps = 0.0f;
    std::string fpsText;

    Font font;
    if (!font.loadFromFile("assets/ArialCEBoldItalic.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }

    Text fpsDisplay;
    fpsDisplay.setFont(font);
    fpsDisplay.setCharacterSize(24);
    fpsDisplay.setFillColor(Color::Black);

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

                // Check if any switch was clicked
                SwitchComponent *switches[] = {&topSwitch, &bottomSwitch};
                for (SwitchComponent *sw : switches)
                {
                    if (sw->isClicked(mousePos))
                    {
                        sw->circle.setFillColor(sw->circle.getFillColor() == blueColor ? greenColor : blueColor);
                        sw->isOn = true;
                        break;
                    }
                }
                for (auto &component : gates)
                {
                    if (component->IsClicked(mousePos))
                    {
                        isDragging = true;
                        selectedComponent = component.get();
                        dragOffset = selectedComponent->sprite.getPosition() - static_cast<Vector2f>(mousePos);
                        break;
                    }
                }
            }
            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                isDragging = false;
                selectedComponent = nullptr;
            }
            else if (event.type == Event::MouseMoved)
            {
                if (isDragging && selectedComponent)
                {
                    Vector2i mousePos = Mouse::getPosition(window);
                    selectedComponent->sprite.setPosition(static_cast<Vector2f>(mousePos) + dragOffset);
                }
            }
        }

        window.clear(whiteColor);

        window.draw(topSwitch.circle);
        window.draw(bottomSwitch.circle);

        for (const auto &gate : gates)
        {
            window.draw(gate->sprite);
        }
        for (const auto &bulb : bulbs)
        {
            window.draw(bulb->circle);
        }
        // comments

        // Update FPS
        elapsedTime = clock.getElapsedTime();
        frameCount++;
        if (elapsedTime.asSeconds() >= 1.0f)
        {
            fps = frameCount / elapsedTime.asSeconds();
            frameCount = 0;
            clock.restart();
        }

        fpsText = "FPS: " + std::to_string(static_cast<int>(fps));
        fpsDisplay.setString(fpsText);
        window.draw(fpsDisplay);

        window.display();
    }

    return 0;
}
