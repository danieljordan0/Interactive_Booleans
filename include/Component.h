#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <spdlog/spdlog.h>

using namespace sf;

class Component
{
public:
    enum GateType
    {
        AND,
        OR,
        NOT
    };

    Component(GateType gateTypeVal) : gateType(gateTypeVal) {}

    virtual ~Component() = default; // Virtual destructor for proper cleanup

    virtual bool IsClicked(Vector2i point) const = 0; // Pure virtual method

    GateType gateType;
    Sprite sprite;
    Texture texture;
    bool output;
    bool firstInput;
};

#endif // COMPONENT_H
