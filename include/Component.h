#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "AndGate.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <spdlog/spdlog.h>
#include <iostream>

using namespace sf;

class Component
{
public:
    enum GateType
    {
        AND,
        OR,
        NOT
    }; // Assuming you have defined gate types

    Component(GateType gateTypeVal) : gateType(gateTypeVal)
    {
        if (!texture.loadFromFile("assets/images/gates/AND_gate.png"))
        {
            spdlog::info("Failed to load texture with path");
        }
        sprite.setTexture(texture);
    }

    bool IsClicked(Vector2i point);

    GateType gateType;
    Sprite sprite;
    Texture texture;
};

inline bool Component::IsClicked(Vector2i point)
{
    Vector2f spritePos = sprite.getPosition(); // top left of sprite
    if (point.x >= spritePos.x && point.x <= spritePos.x + 256 &&
        point.y >= spritePos.y && point.y <= spritePos.y + 256)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // COMPONENT_H
