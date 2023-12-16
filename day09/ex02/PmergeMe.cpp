#include "PmergeMe.hpp"

void    parseTheInput(char **av, int ac)
{
    for(int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);
        if (arg.find("-") != std::string::npos)
        {
            throw std::runtime_error("Invalid argument detected!");
        }
        for (int j = 0; j < (int)arg.length();)
        {
            if (!std::isdigit(arg[j++]))
                throw std::runtime_error("Invalid argument detected!");
        }
    } 
}