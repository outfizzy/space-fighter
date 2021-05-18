#include "ship.h"
#include <iostream>

void Ship::setBounds(float left, float top, float width, float height)
{
    this->bounds = sf::FloatRect(left,top,width,height);
}

void Ship::setVelocity(float x, float y)
{
    this->velocity.x = x;
    this->velocity.y = y;
}

void Ship::checkBounds()
{
    sf::FloatRect bounds = this->getGlobalBounds();
    if (bounds.left + this->speed.x <= this->bounds.left
            || bounds.left + bounds.width + this->speed.x >= this->bounds.width)
        this->speed.x = 0;
    if (bounds.top + this->speed.y <= this->bounds.top
            || bounds.top + bounds.height + this->speed.y >= this->bounds.height)
        this->speed.y = 0;
}

bool Ship::collision(const std::unique_ptr<Bullet> &bullet)
{
    if(this->getGlobalBounds().intersects(bullet->getGlobalBounds()))
        return true;
    return false;
}

bool Ship::collision(const std::unique_ptr<Ship> &ship)
{
    if(this->getGlobalBounds().intersects(ship->getGlobalBounds()))
        return true;
    return false;
}
