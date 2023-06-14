#include "input.hpp"
#include "prim_exception.hpp"

namespace prim
{
    void Input::initialize(sf::RenderWindow* window)
    {
        Input::window = window;
        initialized = true;
    }
    
    void Input::assertInitialized()
    {
        if(!initialized) throw PRIM_EXCEPTION("Accessing Input class before it's initialization!");
    }
    
    void Input::update()
    {
        // update key info
        for(int i = 0; i < cast(sf::Keyboard::KeyCount, int); ++i)
        {
            PressInfo& info = keyInfos[i];
            info.consumed = false;
            bool wasPressed = info.pressed;
            info.pressed = sf::Keyboard::isKeyPressed(cast(i, sf::Keyboard::Key));
            info.just = wasPressed != info.pressed;
        }

        // update mouse button info
        for(int i = 0; i < cast(sf::Mouse::ButtonCount, int); ++i)
        {
            PressInfo& info = mouseButtonInfos[i];
            info.consumed = false;
            bool wasPressed = info.pressed;
            info.pressed = sf::Mouse::isButtonPressed(cast(i, sf::Mouse::Button));
            info.just = wasPressed != info.pressed;
        }
    }
    
    Vec2f Input::getMousePos()
    {
        assertInitialized();

        sf::Vector2i mousePosInt = sf::Mouse::getPosition(*window);
        return Vec2f(mousePosInt.x, mousePosInt.y);
    }
    
    bool Input::isPressed(sf::Keyboard::Key key, bool consume)
    {
        PressInfo& info = keyInfos[cast(key, int)];
        bool consumed = info.consumed;
        info.consumed |= consume;
        return info.pressed && !consumed;
    }
    
    bool Input::isPressed(sf::Mouse::Button btn, bool consume)
    {
        PressInfo& info = mouseButtonInfos[cast(btn, int)];
        bool consumed = info.consumed;
        info.consumed |= consume;
        return info.pressed && !consumed;
    }
    
    bool Input::isJustPressed(sf::Keyboard::Key key, bool consume)
    {
        PressInfo& info = keyInfos[cast(key, int)];
        bool consumed = info.consumed;
        info.consumed |= consume;
        return info.pressed && info.just && !consumed;
    }
    
    bool Input::isJustPressed(sf::Mouse::Button btn, bool consume)
    {
        PressInfo& info = mouseButtonInfos[cast(btn, int)];
        bool consumed = info.consumed;
        info.consumed |= consume;
        return info.pressed && info.just && !consumed;
    }
    
    bool Input::isJustReleased(sf::Keyboard::Key key, bool consume)
    {
        PressInfo& info = keyInfos[cast(key, int)];
        bool consumed = info.consumed;
        info.consumed |= consume;
        return !info.pressed && info.just && !consumed;
    }
    
    bool Input::isJustReleased(sf::Mouse::Button btn, bool consume)
    {
        PressInfo& info = mouseButtonInfos[cast(btn, int)];
        bool consumed = info.consumed;
        info.consumed |= consume;
        return !info.pressed && info.just && !consumed;
    }
}