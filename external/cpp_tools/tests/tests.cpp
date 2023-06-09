#include "math_tests.hpp"
#include "testing.hpp"
#include <iostream>

int main()
{
    try
    {
        MathTests::run();
        std::cout << "Tests finished succesfully!" << std::endl;
    }
    catch(prim::TestException ex)
    {
        std::cout << "Test run failed:\n";
        std::cout << ex.what() << std::endl;
    }
    return 0;
}