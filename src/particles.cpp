#include "particles.hpp"
#include "prim_exception.hpp"

namespace prim
{
    ParticleMaster::ParticleMaster(sf::Vector2u borders) : borders(borders), renderImage(new sf::Image())
    {
        renderImage->create(borders, sf::Color(0u, 0u, 0u, 0u));
    }
    
    ParticleMaster::~ParticleMaster()
    {
        delete renderImage;
    }

    void ParticleMaster::trimParticles()
    {
        for(int i = 0; i < maxParticles; ++i)   
        {
            Particle& p = particles[i];
            if(p.position.x > borders.x || p.position.x < 0.0f || p.position.y > borders.y || p.position.y < 0.0f)
            {
                p.active = false;
            }
        }
    }
    
    void ParticleMaster::clearTexture()
    {
        static sf::Color clearColor(0u, 0u, 0u, 0u);

        for(uint i = 0; i < borders.x; ++i)
        {
            for(uint j = 0; j < borders.y; ++j)
            {
                renderImage->setPixel({i, j}, clearColor);
            }
        }
    }
    
    bool ParticleMaster::addParticle(Particle particle)
    {
        for(int i = 0; i < maxParticles; ++i)
        {
            Particle& p = particles[i];
            if(!p.active)
            {
                p = particle;
                p.active = true;
                return true;
            }
        }
        return false;
    }
    
    void ParticleMaster::update(float deltaTime)
    {
        particleCount = 0u;

        // pre-multiply particle mass values with deltaTime
        float massTimeCoefficient[static_cast<int>(ParticleType::__count)];
        for(int i = 0; i < static_cast<int>(ParticleType::__count); ++i)
            massTimeCoefficient[i] = particleMass[i] * deltaTime / forceLevel;

        // update velocity and move particle
        for(int i = 0; i < maxParticles; ++i)
        {
            Particle& p1 = particles[i];
            if(!p1.active) continue;
            ++particleCount;

            // update velocity
            for(int j = i + 1; j < maxParticles; ++j)
            {
                Particle& p2 = particles[j];
                if(!p2.active) continue;
                sf::Vector2f r = p1.position - p2.position;
                if(r.x == 0.0f && r.y == 0.0f)
                    r.x = 0.1f;
                sf::Vector2f rn = r.normalized();
                float force = particleCharge[static_cast<int>(p1.type)] * particleCharge[static_cast<int>(p2.type)] / r.lengthSq();
                p1.velocity += rn * (force / massTimeCoefficient[static_cast<int>(p1.type)]);
                p2.velocity -= rn * (force / massTimeCoefficient[static_cast<int>(p2.type)]);
            }

            // move
            p1.position += p1.velocity * deltaTime;
        }

        trimParticles();
    }
    
    void ParticleMaster::render(sf::Texture* texture)
    {
        if(clearTextureOnRender)
            clearTexture();

        for(int i = 0; i < maxParticles; ++i)
        {
            Particle& p = particles[i];
            if(p.active)
            {
                sf::Vector2u pixelPos(p.position.x, p.position.y);
                renderImage->setPixel(pixelPos, particleColor[static_cast<int>(p.type)]);
            }
        }

        if(!texture->loadFromImage(*renderImage))
            throw PRIM_EXCEPTION("Failed to load texture from image");
    }
    
    void ParticleMaster::removeAllParticles()
    {
        clearTexture();

        for(int i = 0; i < maxParticles; ++i)
        {
            particles[i].active = false;
        }
    }
}