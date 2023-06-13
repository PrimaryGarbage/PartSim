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
    
    void Button::update(float deltaTime, const sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosf(mousePos.x, mousePos.y);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && sprite->getGlobalBounds().contains(mousePosf))
        {
            if(!pressed)
            {
                pressed = true;
                pressed_ev.invoke();
            }
        }
        else
        {
            pressed = false;
        }
    }
    
    void Button::render(sf::RenderWindow& window)
    {
        sf::Vector2f pos = transform.position.toSfVec();
        pos.y = window.getSize().y - pos.y;
        sprite->setPosition(pos);
        window.draw(*sprite);
    }
    
    void Button::setColor(sf::Color color)
    {
        if(sprite)
        {
            sprite->setColor(color);
        }
    }
}