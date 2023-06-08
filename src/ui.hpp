#ifndef __UI_HPP__
#define __UI_HPP__

//fordec
namespace sf
{
    class RenderWindow;
}

namespace prim
{
    class Ui
    {
    public:
        void update(float deltaTime);
        void render(sf::RenderWindow& window);
    };
}

#endif // __UI_HPP__