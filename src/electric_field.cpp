#include "electric_field.hpp"
#include "particle.hpp"

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
}