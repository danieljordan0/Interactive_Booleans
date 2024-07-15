#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "AndGate.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <spdlog/spdlog.h>

using namespace sf;


class Component {
public:
    enum GateType { AND, OR, NOT }; // Assuming you have defined gate types

    Component(GateType gateTypeVal) : gateType(gateTypeVal) {
        if(!texture.loadFromFile("assets/images/gates/AND_gate.png")){
            spdlog::info("Failed to load texture with path");
        }
        sprite.setTexture(texture);
    }

    GateType gateType;
    Sprite sprite;
    Texture texture;
};

#endif // COMPONENT_H
