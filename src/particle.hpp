#ifndef __PARTICLES_HPP__
#define __PARTICLES_HPP__

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "types.hpp"

namespace prim
{
    enum class ParticleType { Electron, Proton, __count };

    struct Particle
    {
        sf::Vector2f position;
        sf::Vector2f velocity;
        ParticleType type;
        bool active{};
    };
}

#endif // __PARTICLES_HPP__