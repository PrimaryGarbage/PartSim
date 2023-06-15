#ifndef __GLOBALS_HPP__
#define __GLOBALS_HPP__

namespace sf
{
    class RenderWindow;
}

namespace prim
{
    class App;
    class ParticleMaster;
    class Ui;

    class Globals
    {
    public:
        static inline App* app{};
        static inline sf::RenderWindow* mainWindow;
        static inline ParticleMaster* particleMaster{};
        static inline Ui* ui{};
    };
}

#endif // __GLOBALS_HPP__