#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include "ui_transform.hpp"
#include "cpp_tools/math/math.hpp"

namespace prim
{
    class Control
    {
    protected:
        UiTransform transform{};
    public:
        Vec2f getPosition() const noexcept;
        float getRotation() const noexcept;
        Vec2f getSize() const noexcept;
        float getWidth() const noexcept;
        float getHeight() const noexcept;

        void setPosition(Vec2f pos) noexcept;
        void setRotation(float rot) noexcept;
        void setSize(Vec2f size) noexcept;
    };
}

#endif // __CONTROL_HPP__