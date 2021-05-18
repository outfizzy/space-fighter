#include "menu.h"

#include <iostream>

Menu::Menu()
{
    if(!font_.loadFromFile("font.ttf"))
        std::cerr<<"File not found";
}

void Menu::draw(sf::RenderWindow& window)
{
    for(const auto& item : buttons_)
    {
        window.draw(*item);
    }
}

void Menu::addButton(std::string text)
{
    auto button = std::make_unique<Button>(text, 150, font_);
    button->setPosition(bounds_.width / 2 - button->getLocalBounds().width / 2,
                      bounds_.height / 2 - button->getLocalBounds().height * 1.5);
    if(buttons_.size() != 0)
        button->setPosition(bounds_.width / 2 - button->getLocalBounds().width / 2,
                            buttons_.back()->getPosition().y + buttons_.back()->getLocalBounds().height + 50);

    buttons_.emplace_back(std::move(button));
}

void Menu::isButtonHovered(sf::Event::MouseMoveEvent mouse_pos)
{
    for(const auto& item : buttons_)
    {
        auto button = dynamic_cast<Button *>(item.get());
        if(button->getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            button->changeColorToHover();
        else
            button->changeColorToDefault();
    }
}

void Menu::setBounds(sf::FloatRect rect)
{
    bounds_ = rect;
}

Button* Menu::getButtonPressed(sf::Event::MouseButtonEvent mouse_pos)
{
    for(const auto& item : buttons_)
    {
        auto button = dynamic_cast<Button *>(item.get());
        if(button->getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            return button;
    }

    return nullptr;
}
