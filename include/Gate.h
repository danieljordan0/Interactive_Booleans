#ifndef GATE_H
#define GATE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

using namespace sf;

enum class GateType {
    AND_GATE,
    OR_GATE,
    NOT_GATE,
};

struct Gate{
    Texture texture;
    Sprite sprite;
    Vector2f position; 
};

bool createGate(GateType type, const std::string& textureFilePath, const Vector2f& gatePosition, std::unordered_map<GateType, Gate>& gates, std::vector<Sprite>& sprites);

#endif