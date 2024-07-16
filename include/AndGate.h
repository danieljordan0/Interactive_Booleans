#ifndef ANDGATE_H
#define ANDGATE_H

#include "Component.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class AndGate : public Component
{
public:
    AndGate() : Component(AND)
    {
        // Load texture specific to AndGate
        if (!texture.loadFromFile("assets/images/gates/AND_gate.png"))
        {
            spdlog::info("Failed to load texture for AndGate");
        }
        sprite.setTexture(texture);
    }

    bool secondInput;

    bool IsClicked(Vector2i point) const override
    {
        // Check if the point is within the sprite bounds
        FloatRect bounds = sprite.getGlobalBounds();
        return bounds.contains(static_cast<Vector2f>(point));
    }
};

#endif // ANDGATE_H
