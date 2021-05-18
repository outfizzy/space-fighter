#ifndef ENEMY_H
#define ENEMY_H

#include "ship.h"

class Enemy : public Ship
{
public:
    Enemy(int points) : Ship(points) {};
    virtual ~Enemy() = default;
    void movement(sf::Time deltaTime);
};

#endif // ENEMY_H
