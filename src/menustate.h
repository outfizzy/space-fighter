#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "gamestate.h"
#include "menu.h"
#include "playingstate.h"

#include <iostream>
#include <vector>

class PlayingState;
class MenuState: public GameState
{
public:
    MenuState();
    MenuState(PlayingState& playing_state)  : playingState_(playing_state) {};

    GameState* handleEvent(const sf::Event&) override;
    void update(sf::Time) override;
    void render(sf::RenderWindow& window) override;
    void setBounds(sf::Vector2u size);
    void createMenu();
private:
    Menu menu_;
    PlayingState& playingState_;
};


#endif // MENUSTATE_H
