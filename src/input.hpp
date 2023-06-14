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
        static inline sf::RenderWindow* window;
        static inline bool initialized{};

        static void initialize(sf::RenderWindow* window);
        static void assertInitialized();
    public:
        static void update();
        static Vec2f getMousePos();
        static bool isPressed(sf::Keyboard::Key key, bool consume = false);
        static bool isPressed(sf::Mouse::Button btn, bool consume = false);
        static bool isJustPressed(sf::Keyboard::Key key, bool consume = false);
        static bool isJustPressed(sf::Mouse::Button btn, bool consume = false);
        static bool isJustReleased(sf::Keyboard::Key key, bool consume = false);
        static bool isJustReleased(sf::Mouse::Button btn, bool consume = false);
    };

}

#endif // __INPUT_HPP__