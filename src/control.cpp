#include "control.hpp"

namespace prim
{
    Vec2f Control::getPosition() const noexcept
    {
        return transform.position;
    }
    
    float Control::getRotation() const noexcept
    {
        return transform.rotation;
    }
    
    Vec2f Control::getSize() const noexcept
    {
        return transform.size;
    }
    
    float Control::getWidth() const noexcept
    {
        return transform.size.x;
    }
    
    float Control::getHeight() const noexcept
    {
        return transform.size.y;
    }
    
    void Control::setPosition(Vec2f pos) noexcept
    {
        transform.position = pos;
    }
    
    void Control::setRotation(float rot) noexcept
    {
        transform.rotation = rot;
    }
    
    void Control::setSize(Vec2f size) noexcept
    {
        transform.size = size;
    }
}