#ifndef __MATH_TESTS_HPP__
#define __MATH_TESTS_HPP__

#include "testing.hpp"
#include "math/math.hpp"
#include <iostream>

class MathTests
{
public:
    inline static void vec2_sum()
    {
        const prim::Vec2f vec1(1.0f, 2.0f);
        const prim::Vec2f vec2(2.0f, 4.3f);

        prim::Vec2f result = vec1 + vec2;

        ASSERT(result.x == 3.0f, "Value of 'x' is incorrect.");
        ASSERT(result.y == 6.3f, "Value of 'y' is incorrect.");
    }

    inline static void vec2_sub()
    {
        const prim::Vec2f vec1(1.0f, 2.0f);
        const prim::Vec2f vec2(2.0f, 6.0f);

        prim::Vec2f result = vec2 - vec1;

        ASSERT(result.x == 1.0f, "Value of 'x' is incorrect.");
        ASSERT(result.y == 4.0f, "Value of 'y' is incorrect.");
    }

    inline static void vec2_mult()
    {
        const prim::Vec2f vec1(1.0f, 2.0f);
        const prim::Vec2f vec2(2.0f, 4.3f);

        prim::Vec2f result = vec1 * vec2;

        ASSERT(result.x == 2.0f, "Value of 'x' is incorrect.");
        ASSERT(result.y == 8.6f, "Value of 'y' is incorrect.");
    }

    inline static void vec2_div()
    {
        const prim::Vec2f vec1(1.0f, 2.0f);
        const prim::Vec2f vec2(2.0f, 4.0f);

        prim::Vec2f result = vec2 / vec1;

        ASSERT(result.x == 2.0f, "Value of 'x' is incorrect.");
        ASSERT(result.y == 2.0f, "Value of 'y' is incorrect.");
    }

    inline static void vec2_dot()
    {
        const prim::Vec2f vec1(1.0f, 2.0f);
        const prim::Vec2f vec2(2.0f, 4.0f);

        float result = vec1.dot(vec2);

        ASSERT(result == 10.0f, "Value of dot product is incorrect.");
    }

    inline static void vec2_scalar_mult()
    {
        const prim::Vec2f vec(1.0f, 2.0f);
        const float scalar = 5.0f;

        prim::Vec2f result = vec * scalar;

        ASSERT(result.x == 5.0f && result.y == 10.0f, "Value of scalar multiplication is incorrect.");
    }
    inline static void vec2_scalar_div()
    {
        const prim::Vec2f vec(4.0f, 6.0f);
        const float scalar = 2.0f;

        prim::Vec2f result = vec / scalar;

        ASSERT(result.x == 2.0f && result.y == 3.0f, "Value of scalar division is incorrect.");
    }
    inline static void vec2_lengthSq()
    {
        const prim::Vec2f vec(2.0f, 2.0f);

        ASSERT(vec.lengthSq() == 8.0f, "Vec length squared is incorrect.");
    }
    inline static void vec2_length()
    {
        const prim::Vec2f vec(3.0f, 4.0f);

        ASSERT(vec.length() == 5.0f, "Vec length is incorrect.");
    }

    inline static void run()
    {
        vec2_sum();
        vec2_sub();
        vec2_mult();
        vec2_div();
        vec2_dot();
        vec2_scalar_mult();
        vec2_scalar_div();
        vec2_length();
        vec2_lengthSq();
    }
};


#endif // __MATH_TESTS_HPP__