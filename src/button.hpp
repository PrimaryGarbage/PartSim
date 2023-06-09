#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "types.hpp"
#include "ui_transform.hpp"
#include <string>
#include "event.hpp"
#include "SFML/Graphics.hpp"

namespace prim
{
    class Button
    {
    private:
    public:
        bool pressed{};
        UiTransform transform;
        Unp<sf::Sprite> sprite;
        Event<> pressed_ev;

        Button();
        Button(std::string imagePath);
        ~Button();

        sf::FloatRect getRect();
    };
}

#endif // __BUTTON_HPP__