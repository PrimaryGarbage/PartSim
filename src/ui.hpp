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
    public:
        Ui();

        std::vector<Unp<Button>> buttons;

        void update(float deltaTime);
        void render(sf::RenderWindow& window);
    };
}

#endif // __UI_HPP__