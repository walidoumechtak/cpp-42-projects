#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        try
        {
            parseTheInput(av, ac);
            run();
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

    }
    else
    {
        std::cout << "Check you arguments please!!" << std::endl;
        return 1;
    }
    return 0;
}