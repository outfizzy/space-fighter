#include "game.h"

Game::Game() {
    window_.create({800,600}, "Space Fighter");
    window_.setFramerateLimit(1000);

    menuState_.setBounds(window_.getSize());
    menuState_.createMenu();

    currentState_ = &menuState_;
}

void Game::run() {
    sf::Clock clock;

    while (window_.isOpen()) {
        // handle user-input
        sf::Event event;
        while (window_.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window_.close();
            GameState* nextState = currentState_->handleEvent(event);
            if (nextState) // must change state?
                currentState_ = nextState;
            else
                window_.close();
        }

        // update game world
        auto deltaTime = clock.restart();
        currentState_->update(deltaTime);

        currentState_->render(window_);
    }
}
