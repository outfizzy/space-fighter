#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button: public sf::Text
{
public:
    Button();
    Button(std::string text, unsigned font_size, const sf::Font& font);
//    Button(std::string text, unsigned font_size, const sf::Font& font,
//           sf::Color font_color = sf::Color::White);
    void changeColorToHover();
    void changeColorToDefault();
private:
    sf::Color color_default_ = sf::Color::White;
    sf::Color color_hover_ = sf::Color::Cyan;
};

#endif // BUTTON_H
