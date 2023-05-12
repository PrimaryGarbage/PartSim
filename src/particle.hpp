#ifndef __PARTICLE_HPP__
#define __PARTICLE_HPP__

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

    class ParticleMaster
    {
    private:
        static const uint maxParticles = 1000u;
        static inline float particleCharge[] = {
            -1.0f,
            1.0f
        };
        static inline float particleMass[] = {
            0.0001f,
            10.0f,
        };
        static inline sf::Color particleColor[] = {
            sf::Color::Blue,
            sf::Color::Red,
        };

        sf::Vector2u borders;
        Particle particles[maxParticles];
        sf::Image* renderImage;
        bool clearTexture = true;
        uint particleCount{};

        void trim();
    public: 
        ParticleMaster(sf::Vector2u borders);
        ~ParticleMaster();

        bool addParticle(Particle particle);
        void update(float deltaTime);
        void render(sf::Texture* texture);
        inline void setClearTexture(bool enabled) { clearTexture = enabled; }
        inline uint getParticleCount() const { return particleCount; }
    };
}

#endif // __PARTICLE_HPP__