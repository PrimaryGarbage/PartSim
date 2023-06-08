#ifndef __PARTICLE_MASTER_HPP__
#define __PARTICLE_MASTER_HPP__

#include "types.hpp"
#include "particle.hpp"

namespace prim
{
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
        static inline float particleRadius[] = {
            0.6f,
            2.0f,
        };
        static inline const float forceLevel = 0.01f;

        sf::Vector2u bounds;
        Particle particles[maxParticles];
        sf::Image* renderImage;
        uint particleCount{};

        void trimParticles();
        void clearTexture();

        template<class T>
        bool isInBounds(sf::Vector2<T> vec) const;
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

#include "particle_master.tpp"

#endif // __PARTICLE_MASTER_HPP__