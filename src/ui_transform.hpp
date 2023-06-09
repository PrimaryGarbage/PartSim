#ifndef __UI_TRANSFORM_HPP__
#define __UI_TRANSFORM_HPP__

#include "SFML/System.hpp"
#include "cpp_tools/math/math.hpp"

namespace prim
{
    struct UiTransform
    {
        Vec2f position{};
        float rotation{};
        Vec2f size{};
    };
}

#endif // __UI_TRANSFORM_HPP__