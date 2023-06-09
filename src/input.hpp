#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include "cpp_tools/math/math.hpp"
#include "SFML/Graphics.hpp"
#include "types.hpp"

namespace prim
{

    struct PressInfo
    {
        bool pressed{};
        bool just{};
        bool consumed{};
    };

    class Input
    {
        friend class App;
    private:
        static inline PressInfo keyInfos[cast(sf::Keyboard::KeyCount, int)];
        static inline PressInfo mouseButtonInfos[cast(sf::Mouse::ButtonCount, int)];
        static inline float mouseWheelDelta{};
        static inline sf::RenderWindow* window;
        static inline bool initialized{};
        static inline Vec2f mousePos;

        static void initialize(sf::RenderWindow* window);
        static void assertInitialized();
        static void handleEvent(const sf::Event& event);
    public:
        static void clear();
        static Vec2f getMousePos();
        static float getMouseWheelDelta();
        static bool isPressed(sf::Keyboard::Key key);
        static bool isPressed(sf::Mouse::Button btn);
        static bool isJustPressed(sf::Keyboard::Key key);
        static bool isJustPressed(sf::Mouse::Button btn);
        static bool isJustReleased(sf::Keyboard::Key key);
        static bool isJustReleased(sf::Mouse::Button btn);
        static void consume(sf::Keyboard::Key key);
        static void consume(sf::Mouse::Button btn);
    };

}

#endif // __INPUT_HPP__