#include "menustate.h"
#include "button.h"

void MenuState::update(sf::Time) { /* do nothing */ }

GameState* MenuState::handleEvent(const sf::Event& event)
{
    // remain in the current state
    if(event.type == sf::Event::MouseButtonPressed)
    {
        auto button = menu_.getButtonPressed(event.mouseButton);
        if(button)
        {
            if(button->getString().toAnsiString().compare("PLAY") == 0)
                return &playingState_;
            else if(button->getString().toAnsiString().compare("EXIT") == 0)
                return nullptr;
        }
    }

    if(event.type == sf::Event::MouseMoved)
    {
        menu_.isButtonHovered(event.mouseMove);
    }

    return this; // no transition
}

void MenuState::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    menu_.draw(window);
    window.display();
}

void MenuState::setBounds(sf::Vector2u size) {
    menu_.setBounds({0, 0, (float)size.x, (float)size.y});
}

void MenuState::createMenu()
{
    menu_.addButton("PLAY");
    menu_.addButton("EXIT");
}
