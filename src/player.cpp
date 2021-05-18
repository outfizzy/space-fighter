#include "player.h"
#include <iostream>

void Player::movement(sf::Time deltaTime)
{
    sf::Vector2f speed = {
        this->velocity.x * deltaTime.asSeconds(),
        this->velocity.y * deltaTime.asSeconds()
    };

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        this->speed.y = -speed.y;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        this->speed.y = speed.y;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        this->speed.x = -speed.x;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        this->speed.x = speed.x;

    this->checkBounds();

    this->move(this->speed);
    this->speed = {0,0};
}

void Player::shoot(std::vector<std::unique_ptr<Bullet>> &bullets)
{
    auto bullet = std::make_unique<Bullet>(10);
    bullet->setBounds(this->bounds);
    sf::FloatRect bounds = this->getGlobalBounds();

    sf::Vector2f bullet_position = {
        bounds.left + bounds.width,
        (bounds.top + bounds.top + bounds.height) / 2 - bullet->getRadius()
    };

    bullet->setPosition(bullet_position);
    bullets.emplace_back(std::move(bullet));
}
