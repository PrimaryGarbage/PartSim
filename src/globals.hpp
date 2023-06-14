#ifndef __GLOBALS_HPP__
#define __GLOBALS_HPP__

namespace prim
{
    class App;
    class ParticleMaster;
    class Ui;

    class Globals
    {
    public:
        static inline App* app{};
        static inline ParticleMaster* particleMaster{};
        static inline Ui* ui{};
    };
}

#endif // __GLOBALS_HPP__