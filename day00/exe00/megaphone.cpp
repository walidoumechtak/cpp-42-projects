#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            av[i][j] = toupper(av[i][j]);
            j++;
        }
        std::cout << av[i];
        if (i == ac - 1)
            std::cout << "\n";
        i++;    
    }
}