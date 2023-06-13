#ifndef __PARTICLE_MASTER_HPP__
#define __PARTICLE_MASTER_HPP__

#include "types.hpp"
#include "particle.hpp"
#include "field.hpp"
#include <vector>

namespace prim
{
    class ParticleMaster
    {
    private:
        // parameters
        static const uint maxParticles = 1000u;
        static inline const float electricForceLevel = 1.0f;

        sf::Vector2u bounds;
        Particle particles[maxParticles];
        sf::Image renderImage;
        sf::Texture renderTexture;
        Unp<sf::Sprite> renderSprite;
        uint particleCount{};
        std::vector<Unp<Field>> fields;

        void trimParticles();
        void clearRenderImage();

        template<class T>
        bool isInBounds(sf::Vector2<T> vec) const;
    public: 
        bool clearTextureOnRender = true;

        ParticleMaster(sf::Vector2u borders);
        ~ParticleMaster();

        bool addParticle(const Particle& particle);
        void addField(Field* field);
        void update(float deltaTime);
        void render(sf::RenderWindow& window);
        void removeAllParticles();
        inline uint getParticleCount() const { return particleCount; }
    };
}

#include "particle_master.tpp"

#endif // __PARTICLE_MASTER_HPP__