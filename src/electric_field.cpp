#include "electric_field.hpp"
#include "particle.hpp"
#include "vec_utils.hpp"
#include "input.hpp"

namespace prim
{
    ElectricField::ElectricField(const sf::Vector2f force) : force(force)
    {}

    ElectricField::~ElectricField()
    {}

    void ElectricField::affect(Particle* particle, float deltaTime) const 
    {
        sf::Vector2f velocity = force * Particle::info[particle->type].charge / Particle::info[particle->type].mass * deltaTime;
        particle->velocity += velocity;
    }
    
    void ElectricField::update(float deltaTime)
    {
        if(isInside(Input::getMousePos().toSfVec()))
        {
            if(Input::isPressed(sf::Keyboard::LShift))
                force += normalize(force) * Input::getMouseWheelDelta() / 20000.0f ;
            else
                force = rotate(force, Input::getMouseWheelDelta() / 10.0f);
        }
    }
    
    void ElectricField::render(sf::RenderWindow& window)
    {
        Field::render(window);

        sf::Rect<float> bounds = getBounds();
        sf::Vector2f center = bounds.getPosition() + bounds.getSize() * 0.5f;
        const sf::Vertex arrowVertices[] = {
            sf::Vertex(center, sf::Color::Blue),
            sf::Vertex(center + force * 100000.0f, sf::Color::Red),
        };

        window.draw(arrowVertices, 2, sf::PrimitiveType::Lines);
    }
}