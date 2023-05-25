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

    class ParticleMaster
    {
    private:
        // parameters
        static const uint maxParticles = 1000u;
        static inline float particleCharge[] = {
            -1.0f,
            1.0f
        };
        static inline float particleMass[] = {
            0.01f,
            100.0f,
        };
        static inline sf::Color particleColor[] = {
            sf::Color::Blue,
            sf::Color::Red,
        };
        static inline const float forceLevel = 0.01f;

        sf::Vector2u borders;
        Particle particles[maxParticles];
        sf::Image* renderImage;
        uint particleCount{};

        void trimParticles();
        void clearTexture();
    public: 
        bool clearTextureOnRender = true;

        ParticleMaster(sf::Vector2u borders);
        ~ParticleMaster();

        bool addParticle(Particle particle);
        void update(float deltaTime);
        void render(sf::Texture* texture);
        void removeAllParticles();
        inline uint getParticleCount() const { return particleCount; }
    };
}

#endif // __PARTICLES_HPP__