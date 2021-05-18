#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
#include <iostream>
#include "menustate.h"
#include "playingstate.h"

class Game
{
private:
    sf::RenderWindow window_;

    MenuState menuState_ = MenuState(playingState_);
//    PausedState pausedState_;
    PlayingState playingState_ = PlayingState(menuState_);

    GameState *currentState_;
public:
    Game();
    void run();
};

#endif // GAME_H
