#ifndef __APP_HPP__
#define __APP_HPP__

#include "prim_exception.hpp"
#include "types.hpp"
#include "particle_master.hpp"
#include "ui.hpp"
#include <vector>

// fordec
namespace sf
{
    class RenderWindow;
    class Texture;
    class Event;
    class Font;
}
//

namespace prim
{
    class App final
    {
    private:
        sf::RenderWindow* window;
        sf::Font* font;
        ParticleMaster particleMaster;
        Ui ui;
        float deltaTime{};

        void mainLoop();
        void handleInput();
        void printInfo(float deltaTime);
    public:
        App();
        ~App();
        int run();
    };
}

#endif // __APP_HPP__