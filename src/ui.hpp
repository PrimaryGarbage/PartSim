#ifndef __UI_HPP__
#define __UI_HPP__

#include <vector>
#include "button.hpp"

//fordec
namespace sf
{
    class RenderWindow;
}
//

namespace prim
{
    class Ui
    {
    private:
        sf::RenderWindow* window;
    public:
        std::vector<Unp<Button>> buttons;

        Ui(sf::RenderWindow* window);

        void update(float deltaTime);
        void render();

        inline void setWindow(sf::RenderWindow* window) { this->window = window; }
    };
}

#endif // __UI_HPP__