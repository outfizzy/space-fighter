#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "bullet.h"

class Ship : public sf::ConvexShape
{
protected:
    sf::Vector2f velocity = {150,150};
    sf::Vector2f speed = {0,0};
    sf::FloatRect bounds = {0,0,0,0};
    void checkBounds();

public:
    Ship(int points) : sf::ConvexShape(points){};
    virtual ~Ship() = default;
    void setBounds(float left, float top, float width, float height);
    void setVelocity(float x, float y);
    bool collision(const std::unique_ptr<Bullet>&);
    bool collision(const std::unique_ptr<Ship>&);
};

#endif // SHIP_H
