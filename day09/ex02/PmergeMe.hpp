#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>

void    parseTheInput(char **av, int ac);

template <typename Container>
void    run(Container &data)
{
    
}

template <typename Container>
void    fillTheData(Container &data, char **av, int ac)
{
    int num;

    for (int i = 1; i < ac; i++)
    {
        num = strtod(av[i], NULL);
        data.push_back(num);
    }
}

#endif