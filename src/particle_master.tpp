#ifndef __PARTICLES_TPP__
#define __PARTICLES_TPP__

#include "particle_master.hpp"

namespace prim
{
    template<class T>
    bool ParticleMaster::isInBounds(sf::Vector2<T> vec) const
    {
        return vec.x < bounds.x && vec.x > 0.0f && vec.y < bounds.y && vec.y > 0.0f;
    }
}

#endif // __PARTICLES_TPP__