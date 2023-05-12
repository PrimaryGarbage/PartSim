#ifndef __APP_HPP__
#define __APP_HPP__

#include "prim_exception.hpp"
#include "types.hpp"
#include "particles.hpp"
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
        sf::Texture* mainTexture;
        sf::Sprite* mainSprite;
        sf::Font* font;
        ParticleMaster particleMaster;
        float deltaTime{};

        void mainLoop();
        void handleInput(const sf::Event& event);
        void handleEvent(const sf::Event& event);
        void printInfo(float deltaTime);
    public:
        App();
        ~App();
        int run();
    };
}

#endif // __APP_HPP__