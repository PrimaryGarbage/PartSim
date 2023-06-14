#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "SFML/System.hpp"
#include <cmath>

namespace prim
{
    template<class T>
    float lengthSq(sf::Vector2<T> vec)
    {
        return vec.x * vec.x + vec.y * vec.y;
    }

    template<class T>
    float length(sf::Vector2<T> vec)
    {
        return std::sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    template<class T>
    sf::Vector2f normalize(sf::Vector2<T> vec)
    {
        return vec / length(vec);
    }
}

#endif // __UTILS_HPP__