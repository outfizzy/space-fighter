#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

struct GameState {
    virtual GameState* handleEvent(const sf::Event&) = 0;
    virtual void update(sf::Time) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual ~GameState() = default;
};

#endif // GAMESTATE_H
