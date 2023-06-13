#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "types.hpp"
#include "ui_transform.hpp"
#include <string>
#include "event.hpp"
#include "control.hpp"
#include "SFML/Graphics.hpp"

namespace prim
{
    class Button : public Control
    {
    private:
        bool pressed{};
        Unp<sf::Sprite> sprite;
    public:
        Event<> pressed_ev;

        Button();
        Button(std::string imagePath);
        ~Button();

        void update(float deltaTime, const sf::RenderWindow& window);
        void render(sf::RenderWindow& window);
        void setColor(sf::Color color);
        inline bool isPressed() const { return pressed; }
    };
}

#endif // __BUTTON_HPP__