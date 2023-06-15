#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "SFML/System.hpp"
#include <cmath>

namespace prim
{
    template<class T>
    float lengthSq(const sf::Vector2<T>& vec)
    {
        return vec.x * vec.x + vec.y * vec.y;
    }

    template<class T>
    float length(const sf::Vector2<T>& vec)
    {
        return std::sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    template<class T>
    sf::Vector2f normalize(const sf::Vector2<T>& vec)
    {
        return vec / length(vec);
    }

    template<class T>
    sf::Vector2f rotate(const sf::Vector2<T>& vec, float angle)
    {
        float cos = std::cos(angle);
        float sin = std::sin(angle);
        return { vec.x * cos - vec.y * sin, vec.x * sin + vec.y * cos };
    }
}

#endif // __UTILS_HPP__