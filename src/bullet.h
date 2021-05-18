#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet : public sf::CircleShape
{
private:
    sf::Vector2f velocity = {200, 200};
    sf::Vector2f speed = {0, 0};
    sf::FloatRect bounds = {0, 0, 0, 0};
public:
    Bullet(float radius) : sf::CircleShape(radius) {};
    virtual ~Bullet() = default;
    void animate(sf::Time deltaTime);
    void setBounds(sf::FloatRect rect);
    bool isOutOfBounds();
};

#endif // BULLET_H
