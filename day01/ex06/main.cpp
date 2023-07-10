#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl o;
    if (ac == 1)
    {
        std::cerr << "Number of argument is not correct !!!" << std::endl;
    }
    o.complain(av[1]);
}