#include "button.h"

Button::Button()
{

}

Button::Button(std::string text, unsigned font_size, const sf::Font& font)
{
    setFont(font);
    setCharacterSize(font_size);
    setString(text);
}

void Button::changeColorToHover()
{
    setFillColor(color_hover_);
}
void Button::changeColorToDefault()
{
    setFillColor(color_default_);
}
