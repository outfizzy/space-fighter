#include "playingstate.h"

#include <iostream>

PlayingState::PlayingState(MenuState& menuState) : menuState_(menuState)
{
    setGame();
}

void PlayingState::update(sf::Time deltaTime) {
    auto player = dynamic_cast<Player *>(player_.get());
    player->movement(deltaTime);

    for (const auto &e : enemies_)
    {
        auto enemy = dynamic_cast<Enemy *>(e.get());
        enemy->movement(deltaTime);
    }

    for (const auto &b : bullets_)
        b->animate(deltaTime);
}

GameState* PlayingState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed)
    {

        if (event.key.code == sf::Keyboard::Escape)
        {
            resetGame();
            return &menuState_; // back to menu
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            auto player = dynamic_cast<Player *>(player_.get());
            player->shoot(bullets_);
        }
    }

    return this; // no transition
}

void PlayingState::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    // generate wave
    if(enemies_.size() == 0
            && bullets_.size() == 0)
        nextWave();

    // bullet collision
    for(Bullets::iterator bullet = bullets_.begin();
        bullet != bullets_.end(); ++bullet)
    {
        // if escape from bounds
        if(bullet->get()->isOutOfBounds())
        {
            bullets_.erase(bullet);
            break;
        }

        // if hit enemy
        for(Enemies::iterator enemy = enemies_.begin();
            enemy != enemies_.end(); ++enemy)
        {
            auto e = dynamic_cast<Enemy *>(enemy->get());
            if(e->collision(*bullet))
            {
                bullets_.erase(bullet);
                enemies_.erase(enemy);
                return;
            }
        }
    }

    // enemy collision
    for(Enemies::iterator enemy = enemies_.begin();
        enemy != enemies_.end(); ++enemy)
    {
        auto e = dynamic_cast<Enemy *>(enemy->get());
        if(e->collision(player_))
        {
            resetGame();
            break;
        }
    }


    window.draw(*player_);

    for (const auto &e : enemies_)
    {
        auto enemy = dynamic_cast<Enemy *>(e.get());
        window.draw(*enemy);
    }

    for (const auto &b : bullets_)
        window.draw(*b);

    window.display();
}

void PlayingState::setGame()
{
    createPlayer();
}

void PlayingState::resetGame()
{
    bullets_.clear();
    enemies_.clear();
    player_->setPosition(100,200);
}

void PlayingState::createPlayer()
{
    player_ = std::make_unique<Player>(3);
    player_->setPoint(0, sf::Vector2f(0,25));
    player_->setPoint(1, sf::Vector2f(0,-25));
    player_->setPoint(2, sf::Vector2f(50,0));
    player_->setBounds(0, 0, 800 / 2, 600);
    player_->setFillColor(sf::Color::Cyan);
    player_->setPosition(100,200);
}

void PlayingState::nextWave()
{
    int y = 50;
    while(y < 600)
    {
        auto enemy = std::make_unique<Enemy>(3);
        enemy->setPoint(0, sf::Vector2f(0,25));
        enemy->setPoint(1, sf::Vector2f(0,-25));
        enemy->setPoint(2, sf::Vector2f(-50,0));
        enemy->setFillColor(sf::Color::Red);
        enemy->setPosition(800 * 1.1, y);
        enemy->setVelocity(50,50);
        enemies_.emplace_back(std::move(enemy));

        y += 100;
    }
}

