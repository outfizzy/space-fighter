#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "gamestate.h"
#include "menustate.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "ship.h"

typedef std::vector<std::unique_ptr<sf::Drawable>> Enemies;
typedef std::vector<std::unique_ptr<Bullet>> Bullets;

class MenuState;
class PlayingState: public GameState
{
public:
    PlayingState();
    PlayingState(MenuState& menuState);

    GameState* handleEvent(const sf::Event&) override;
    void update(sf::Time) override;
    void render(sf::RenderWindow& window) override;
private:
    MenuState& menuState_;
    std::unique_ptr<Ship> player_ = nullptr;
    Enemies enemies_;
    Bullets bullets_;


    void setGame();
    void resetGame();
    void createPlayer();
    std::unique_ptr<Enemy> createEnemy();
    void nextWave();
};

#endif // PLAYINGSTATE_H
