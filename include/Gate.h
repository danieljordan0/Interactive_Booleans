#ifndef GATE_H
#define GATE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

using namespace sf;

enum class GateType {
    AND,
    OR,
    NOT,
};

#endif