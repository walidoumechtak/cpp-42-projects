#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        std::vector<int> data;
        try
        {
            parseTheInput(av, ac);
            fillTheData(data, av, ac);
            run(data);
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