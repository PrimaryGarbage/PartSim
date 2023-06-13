#include "field.hpp"
#include "prim_exception.hpp"

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
        image.create({1u, 1u}, sf::Color::White);
        sf::Texture texture;
        if(!texture.loadFromImage(image)) throw PRIM_EXCEPTION("Field failed to load image from memory.");
        sprite = std::make_unique<sf::Sprite>(texture);
    }


    bool Field::isInside(sf::Vector2f point) const
    {
        return bounds.contains(point);
    }
    
    void Field::setBounds(sf::Rect<float> bounds)
    {
        this->bounds = bounds;
        sprite->setPosition(bounds.getPosition());
        sprite->setScale(bounds.getSize());
    }
    
    sf::Rect<float> Field::getBounds() const
    {
        return this->bounds;
    }

    void Field::setColor(const sf::Color& color)
    {
        sprite->setColor(color);
    }
    
    void Field::update(float deltaTime)
    {
        
    }
    
    void Field::render(sf::RenderWindow& window)
    {
        window.draw(*sprite);
    }
}