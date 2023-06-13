#include "repelling_field.hpp"
#include "particle.hpp"

namespace prim
{
    RepellingField::RepellingField(float force) : force(force)
    {}
    
    RepellingField::~RepellingField()
    {}
    
    void RepellingField::affect(Particle* particle, float deltaTime) const 
    {
        sf::Vector2f center = bounds.getPosition() + bounds.getSize() / 2.0f;
        sf::Vector2f direction = particle->position - center;
        float distanceCoef = bounds.width / direction.length();
        particle->velocity += direction.normalized() * distanceCoef * distanceCoef * (force / Particle::info[particle->type].mass);
    }
}