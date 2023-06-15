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
    enum class Brush { Particle, Field, Erase, __len };
    inline const char* Brush_str[] = { "Particle", "Field", "Erase" };

    class Ui
    {
    private:
        Brush currentBrush{};
    public:
        Ui();

        std::vector<Unp<Button>> buttons;

        void update(float deltaTime);
        void render(sf::RenderWindow& window);
        inline Brush getCurrentBrush() const { return currentBrush; };
    };
}

#endif // __UI_HPP__