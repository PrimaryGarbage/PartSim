#ifndef __PARTICLES_HPP__
#define __PARTICLES_HPP__

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "types.hpp"
#include <unordered_map>

namespace prim
{
    enum class ParticleType { Electron, Proton, __count };

    struct ParticleInfo
    {
        float charge;
        float mass;
        sf::Color color;
        float radius;
    };

    struct Particle
    {
        static inline std::unordered_map<ParticleType, ParticleInfo> info {
            {ParticleType::Electron, { -1.0f, 1.0f, {0u, 0u, 255u, 255u}, 0.6f }},
            {ParticleType::Proton, { 1.0f, 100.0f, {255u, 0u, 0u, 255u}, 2.0f }}
        };

        sf::Vector2f position;
        sf::Vector2f velocity;
        ParticleType type;
        bool active{};
    };
}

#endif // __PARTICLES_HPP__