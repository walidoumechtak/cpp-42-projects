#include <iostream>
#include <cctype>

/**
 * main - the start of the program
 * @ac: number of argument
 * @av: two dimenstionl array that containe the strings
 * Return: 0 when success or !0 when fail
*/

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
             if (av[i][j] != ' ')
                av[i][j] = toupper(av[i][j]);
        }
        std::cout << av[i];

        if (i != ac - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}