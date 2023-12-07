#include "RPN.hpp"


int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            run(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }    
    }
    else
    {
        std::cerr << "Check you arguments please!" << std::endl;
        return (-1);
    }
    return (0);
}