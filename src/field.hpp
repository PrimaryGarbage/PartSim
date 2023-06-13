#ifndef __FIELD_HPP__
#define __FIELD_HPP__

#include "SFML/Graphics.hpp"
#include "cpp_tools/math/math.hpp"
#include "types.hpp"

// fordec
namespace prim
{
    class Particle;
}
//

namespace prim
{
    class Field
    {
    protected:
        sf::Rect<float> bounds;
        Unp<sf::Sprite> sprite;

        void generateTexture();
    public:
        Field();
        virtual ~Field();

        bool isInside(sf::Vector2f point) const;
        void setBounds(sf::Rect<float> bounds);
        void setColor(const sf::Color& color);
        sf::Rect<float> getBounds() const;
        virtual void affect(Particle* particle, float deltaTime) const = 0;
        virtual void update(float deltaTime);
        virtual void render(sf::RenderWindow& window);
    };
}

#endif // __FIELD_HPP__