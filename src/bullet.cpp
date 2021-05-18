#include "bullet.h"

void Bullet::animate(sf::Time deltaTime)
{
    this->speed.x = this->velocity.y * deltaTime.asSeconds();
    this->move(this->speed);
}

void Bullet::setBounds(sf::FloatRect rect)
{
    this->bounds = sf::FloatRect(rect);
    this->bounds.width *= 2;
}

bool Bullet::isOutOfBounds()
{
    if (this->getGlobalBounds().left +this->getGlobalBounds().width + this->speed.x >= this->bounds.width)
        return true;
    return false;
}
