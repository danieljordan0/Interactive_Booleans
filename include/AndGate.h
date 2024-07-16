#ifndef AndGate_H
#define AndGate_H

#include <string>
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class AndGate : public Component
{
public:
    // 512 x 512
    AndGate() : Component(AND) {}
};

#endif // AndGate_H
