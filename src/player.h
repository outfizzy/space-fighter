#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"
#include "bullet.h"

class Player : public Ship
{
public:
    Player(int points) : Ship(points) {};
    void movement(sf::Time deltaTime);
    void shoot(std::vector<std::unique_ptr<Bullet>> &bullets);
};

#endif // PLAYER_H
