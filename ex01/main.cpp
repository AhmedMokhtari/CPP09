#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Program Usage : ./RPN Arg1" << std::endl;
        return 0;
    }
    RPN a(argv[1]);
    return 0;
}