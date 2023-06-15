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
    
    void Input::handleEvent(const sf::Event& event)
    {
        assertInitialized();

        // reset values

        switch(event.type)
        {
            case sf::Event::KeyPressed:
            {
                keyInfos[event.key.code].pressed = true;
                keyInfos[event.key.code].just = true;
                break;
            }
            case sf::Event::KeyReleased:
            {
                keyInfos[event.key.code].pressed = false;
                keyInfos[event.key.code].just = true;
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                mouseButtonInfos[event.mouseButton.button].pressed = true;
                mouseButtonInfos[event.mouseButton.button].just = true;
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                mouseButtonInfos[event.mouseButton.button].pressed = false;
                mouseButtonInfos[event.mouseButton.button].just = true;
                break;
            }
            case sf::Event::MouseMoved:
            {
                mousePos = Vec2f(event.mouseMove.x, event.mouseMove.y);
                break;
            }
            case sf::Event::MouseWheelScrolled:
            {
                mouseWheelDelta = event.mouseWheelScroll.delta;
                break;
            }
            case sf::Event::Closed:
            {
                window->close();
                break;
            }
            default:
                break;
        }
    }
    
    void Input::clear()
    {
        assertInitialized();

        mouseWheelDelta = 0.0f;

        // clear key info
        for(int i = 0; i < cast(sf::Keyboard::KeyCount, int); ++i)
        {
            PressInfo& info = keyInfos[i];
            info.consumed = false;
            info.just = false;
        }

        // clear mouse button info
        for(int i = 0; i < cast(sf::Mouse::ButtonCount, int); ++i)
        {
            PressInfo& info = mouseButtonInfos[i];
            info.consumed = false;
            info.just = false;
        }
    }
    
    Vec2f Input::getMousePos()
    {
        assertInitialized();

        return mousePos;
    }
    
    float Input::getMouseWheelDelta()
    {
        assertInitialized();

        return mouseWheelDelta;
    }
    
    bool Input::isPressed(sf::Keyboard::Key key)
    {
        assertInitialized();

        PressInfo& info = keyInfos[cast(key, int)];
        return info.pressed && !info.consumed;
    }
    
    bool Input::isPressed(sf::Mouse::Button btn)
    {
        assertInitialized();

        PressInfo& info = mouseButtonInfos[cast(btn, int)];
        return info.pressed && !info.consumed;
    }
    
    bool Input::isJustPressed(sf::Keyboard::Key key)
    {
        assertInitialized();

        PressInfo& info = keyInfos[cast(key, int)];
        bool result = info.pressed && info.just;
        return info.pressed && info.just && !info.consumed;
    }
    
    bool Input::isJustPressed(sf::Mouse::Button btn)
    {
        assertInitialized();

        PressInfo& info = mouseButtonInfos[cast(btn, int)];
        return info.pressed && info.just && !info.consumed;
    }
    
    bool Input::isJustReleased(sf::Keyboard::Key key)
    {
        assertInitialized();

        PressInfo& info = keyInfos[cast(key, int)];
        return !info.pressed && info.just && !info.consumed;
    }
    
    bool Input::isJustReleased(sf::Mouse::Button btn)
    {
        assertInitialized();

        PressInfo& info = mouseButtonInfos[cast(btn, int)];
        return !info.pressed && info.just && !info.consumed;
    }
    
    void Input::consume(sf::Keyboard::Key key)
    {
        assertInitialized();

        keyInfos[cast(key, int)].consumed = true;
    }
    
    void Input::consume(sf::Mouse::Button btn)
    {
        assertInitialized();

        mouseButtonInfos[cast(btn, int)].consumed = true;
    }
}