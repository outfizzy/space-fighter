#ifndef MENU_H
#define MENU_H

#include "button.h"

#include <string>
#include <SFML/Graphics.hpp>

typedef std::vector<std::unique_ptr<sf::Text>> Buttons;

class Menu
{
public:
    Menu();
    void addButton(std::string);
    void setBounds(sf::FloatRect);
    void draw(sf::RenderWindow&);
    void isButtonHovered(sf::Event::MouseMoveEvent);
    Button* getButtonPressed(sf::Event::MouseButtonEvent);
private:
    Buttons buttons_ = {};
    sf::Font font_;
    sf::FloatRect bounds_ = {0,0,0,0};
};

#endif // MENU_H
