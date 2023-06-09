#include "prim_exception.hpp"
#include "button.hpp"

namespace prim
{
    Button::Button()
    {
        sf::Image image;
        image.create({50u, 50u}, sf::Color::White);
        sf::Texture texture;
        if(!texture.loadFromImage(image)) throw PRIM_EXCEPTION("Button failed to load image from file.");
        sprite = std::make_unique<sf::Sprite>(texture);
    }
    
    Button::Button(std::string imagePath)
    {
        sf::Texture texture;
        if(!texture.loadFromFile(imagePath)) throw PRIM_EXCEPTION("Button failed to load image from file.");
        sprite = std::make_unique<sf::Sprite>(texture);
    }
    
    Button::~Button()
    {
    }
    
    sf::FloatRect Button::getRect()
    {
        return sprite->getGlobalBounds();
    }
}