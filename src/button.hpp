#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "types.hpp"

// fordec
namespace sf
{
    class Sprite;
}
//

namespace prim
{
    class Button
    {
    private:
        Unp<sf::Sprite> sprite;
    public:
        ~Button();
    };
}

#endif // __BUTTON_HPP__