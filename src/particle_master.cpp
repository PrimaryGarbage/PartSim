#include "particle_master.hpp"
#include "prim_exception.hpp"

namespace prim
{
    ParticleMaster::ParticleMaster(sf::Vector2u borders) : bounds(borders) 
    {
        renderImage.create(borders, sf::Color(0u, 0u, 0u, 0u));
        if(!renderTexture.loadFromImage(renderImage)) throw PRIM_EXCEPTION("Failed to create render texture for particle master");
        renderSprite = std::make_unique<sf::Sprite>(renderTexture);
    }
    
    ParticleMaster::~ParticleMaster()
    {
    }

    void ParticleMaster::trimParticles()
    {
        for(int i = 0; i < maxParticles; ++i)   
        {
            Particle& p = particles[i];
            if(!isInBounds(p.position))
            {
                p.active = false;
            }
        }
    }
    
    void ParticleMaster::clearRenderImage()
    {
        static sf::Color clearColor(0u, 0u, 0u, 0u);

        for(uint i = 0; i < bounds.x; ++i)
        {
            for(uint j = 0; j < bounds.y; ++j)
            {
                renderImage.setPixel({i, j}, clearColor);
            }
        }
    }
    
    bool ParticleMaster::addParticle(const Particle& particle)
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
    
    void ParticleMaster::addField(Field* field)
    {
        fields.push_back(Unp<Field>(field));
    }
    
    void ParticleMaster::update(float deltaTime)
    {
        // update fields
        for(const Unp<Field>& field : fields)
        {
            field->update(deltaTime);
        }

        particleCount = 0u;

        // pre-multiply particle mass values with deltaTime
        float massTimeCoefficient[static_cast<int>(ParticleType::__count)];
        for(int i = 0; i < static_cast<int>(ParticleType::__count); ++i)
            massTimeCoefficient[i] = Particle::particleInfo[static_cast<ParticleType>(i)].mass * deltaTime / electricForceLevel;

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
                float force = Particle::particleInfo[p1.type].charge * Particle::particleInfo[p2.type].charge / r.lengthSq();
                p1.velocity += rn * (force / massTimeCoefficient[static_cast<int>(p1.type)]);
                p2.velocity -= rn * (force / massTimeCoefficient[static_cast<int>(p2.type)]);
            }

            // affect particle with fields
            for(const Unp<Field>& field : fields)
            {
                if(field->isInside(p1.position))
                    field->affect(&p1, deltaTime);
            }

            // move
            p1.position += p1.velocity * deltaTime;
        }

        trimParticles();
    }
    
    void ParticleMaster::render(sf::RenderWindow& window)
    {
        if(clearTextureOnRender)
            clearRenderImage();


        for(int i = 0; i < maxParticles; ++i)
        {
            Particle& p = particles[i];
            if(p.active)
            {
                float radius = Particle::particleInfo[p.type].radius;
                const sf::Color& color = Particle::particleInfo[p.type].color;

                for(float j = p.position.x - radius; j < p.position.x + radius; j += 1.0f)
                {
                    for(float k = p.position.y - radius; k < p.position.y + radius; k += 1.0f)
                    {
                        sf::Vector2u pixelPos {static_cast<uint>(std::round(j - 0.5f)), static_cast<uint>(std::round(k - 0.5f))};
                        if(isInBounds(pixelPos) && (sf::Vector2f{j, k} - p.position).length() <= radius)
                            renderImage.setPixel(pixelPos, color);
                    }
                }
            }
        }


        renderTexture.update(renderImage);

        window.draw(*renderSprite);

        // render fields
        for(const Unp<Field>& field : fields)
        {
            field->render(window);
        }
    }
    
    void ParticleMaster::removeAllParticles()
    {
        clearRenderImage();

        for(int i = 0; i < maxParticles; ++i)
        {
            particles[i].active = false;
        }
    }
}