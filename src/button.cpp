#include "prim_exception.hpp"
#include "button.hpp"
#include "input.hpp"

namespace prim
{
    Button::Button()
    {
        sf::Image image;
        image.create(1u, 1u, sf::Color::White);
        sf::Texture texture;
        if(!texture.loadFromImage(image)) throw PRIM_EXCEPTION("Button failed to load image from memory.");
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
    
    void Button::update(float deltaTime)
    {
        pressed = false;
        Vec2f mousePos = Input::getMousePos();
        if(sprite->getGlobalBounds().contains(mousePos.toSfVec()) && (Input::isJustReleased(sf::Mouse::Button::Left, true) || Input::isJustReleased(sf::Mouse::Button::Right, true)))
        {
            pressed_ev.invoke();
        }
    }
    
    void Button::render(sf::RenderWindow& window)
    {
        sf::Vector2f pos = transform.position.toSfVec();
        pos.y = window.getSize().y - pos.y;
        sprite->setPosition(pos);
        sprite->setScale(transform.size.toSfVec());
        window.draw(*sprite);
    }
    
    sf::Color Button::getColor() const
    {
        if(sprite)
        {
            return sprite->getColor();
        }
        else
        {
            return sf::Color::Black;
        }
    }
    
    void Button::setColor(sf::Color color)
    {
        if(sprite)
        {
            sprite->setColor(color);
        }
    }
}