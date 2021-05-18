#include "enemy.h"

void Enemy::movement(sf::Time deltaTime)
{
    this->speed = {this->velocity.x * deltaTime.asSeconds(), 0};
    this->move(-speed);
}
