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
            bool wasPressed = keyInfos[i].pressed;
            keyInfos[i].pressed = sf::Keyboard::isKeyPressed(cast(i, sf::Keyboard::Key));
            keyInfos[i].just = wasPressed != keyInfos[i].pressed;
        }

        // update mouse button info
        for(int i = 0; i < cast(sf::Mouse::ButtonCount, int); ++i)
        {
            bool wasPressed = mouseButtonInfos[i].pressed;
            mouseButtonInfos[i].pressed = sf::Mouse::isButtonPressed(cast(i, sf::Mouse::Button));
            mouseButtonInfos[i].just = wasPressed != mouseButtonInfos[i].pressed;
        }
    }
    
    Vec2f Input::getMousePos()
    {
        assertInitialized();

        sf::Vector2i mousePosInt = sf::Mouse::getPosition(*window);
        return Vec2f(mousePosInt.x, mousePosInt.y);
    }
    
    bool Input::isPressed(sf::Keyboard::Key key)
    {
        return keyInfos[cast(key, int)].pressed;
    }
    
    bool Input::isPressed(sf::Mouse::Button btn)
    {
        return mouseButtonInfos[cast(btn, int)].pressed;
    }
    
    bool Input::isJustPressed(sf::Keyboard::Key key)
    {
        return keyInfos[cast(key, int)].pressed && keyInfos[cast(key, int)].just;
    }
    
    bool Input::isJustPressed(sf::Mouse::Button btn)
    {
        return mouseButtonInfos[cast(btn, int)].pressed && mouseButtonInfos[cast(btn, int)].just;
    }
    
    bool Input::isJustReleased(sf::Keyboard::Key key)
    {
        return !keyInfos[cast(key, int)].pressed && keyInfos[cast(key, int)].just;
    }
    
    bool Input::isJustReleased(sf::Mouse::Button btn)
    {
        return !mouseButtonInfos[cast (btn, int)].pressed && mouseButtonInfos[cast(btn, int)].just;
    }
}