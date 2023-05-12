#include "app.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    try
    {
        prim::App app;
        return app.run();
    }
    catch(prim::Exception ex)
    {
        std::cerr << "[EXCEPTION] : " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "[EXCEPTION] Caught unknown exception!" << std::endl;
    }
}