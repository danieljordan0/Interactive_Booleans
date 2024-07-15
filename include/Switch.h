#ifndef SWITCH_H
#define SWITCH_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <spdlog/spdlog.h>
#include <cmath>

using namespace sf;

class SwitchComponent
{
public:
    SwitchComponent(const std::string nameVal, const Vector2f circlePos);

    bool isClicked(Vector2i point);

    CircleShape circle;
    std::string name;
    bool isOn;
    float radius = 50.0f;
};

inline SwitchComponent::SwitchComponent(const std::string nameVal, const Vector2f circlePos)
    : name(nameVal), isOn(false)
{
    circle.setRadius(radius);
    circle.setPointCount(100);
    circle.setPosition(circlePos);
}
inline bool SwitchComponent::isClicked(Vector2i point)
{
    Vector2f switchPos = circle.getPosition();
    Vector2f switchCentre(switchPos.x + radius, switchPos.y + radius);
    float distanceOfPointFromCentre = sqrt(powf(point.x - switchCentre.x, 2) + powf(point.y - switchCentre.y, 2));
    return distanceOfPointFromCentre <= radius;
}

#endif
