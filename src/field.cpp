#include "field.hpp"
#include "prim_exception.hpp"
#include "input.hpp"

namespace prim
{
    Field::Field()
    {
        generateTexture();
    }
    
    Field::~Field()
    {}

    void Field::generateTexture()
    {
        sf::Image image;
        image.create(1u, 1u, sf::Color(255u, 255u, 255u));
        sf::Texture texture;
        if(!texture.loadFromImage(image)) throw PRIM_EXCEPTION("Field failed to load image from memory.");
        sprite = std::make_unique<sf::Sprite>(texture);
        sprite->setColor(sf::Color(255u, 255u, 255u, 40u));
    }


    bool Field::isInside(sf::Vector2f point) const
    {
        return sprite->getGlobalBounds().contains(point);
    }
    
    void Field::setBounds(sf::Rect<float> bounds)
    {
        sprite->setPosition(bounds.getPosition());
        sprite->setScale(bounds.getSize());
    }
    
    sf::Rect<float> Field::getBounds() const
    {
        return sprite->getGlobalBounds();
    }

    void Field::setColor(const sf::Color& color)
    {
        sprite->setColor(color);
    }
    
    void Field::update(float deltaTime)
    {
        if(isInside(Input::getMousePos().toSfVec()))
        {
            sprite->rotate(Input::getMouseWheelDelta());
        }
    }
    
    void Field::render(sf::RenderWindow& window)
    {
        window.draw(*sprite);
    }
}