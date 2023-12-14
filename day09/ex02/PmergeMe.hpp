#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*
    lower and upper bound that are disponible in c++ 98.
    template< class ForwardIt, class T >
    constexpr ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );

    template< class ForwardIt, class T, class Compare >
    constexpr ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
*/

#include <iostream>
#include <exception>
#include <vector>

void    parseTheInput(char **av, int ac);

template <typename Container>
void    splitArray(Container &data, Container &small, Container &big)
{
    // take pair number from data, and compare them
    // the small one goes to small container
    // the big one goes to big container
    // 1 9 2 8 3 7 4 6 5
    for (int i = 0; i < (int)data.size(); i = i + 2)
    {
        if (i + 1 < (int)data.size() && data.at(i) > data.at(i + 1))
        {
            big.push_back(data.at(i));
            small.push_back(data.at(i + 1));
        }
        else if (i + 1 < (int)data.size() && data.at(i) < data.at(i + 1))
        {
            small.push_back(data.at(i));
            big.push_back(data.at(i + 1));
        }
    }
    if (data.size() % 2 != 0)
        big.push_back(data.at(data.size() - 1));
}

template <typename Container>
void print(Container big, Container small)
{
    for (int i = 0; i < (int)big.size(); i++)
        std::cout << big.at(i);
    std::cout << std::endl << std::endl;
    for (int i = 0; i < (int)small.size(); i++)
        std::cout << small.at(i);
    std::cout << std::endl;
}

template <typename Container>
void    sortBig(Container big)
{
    
}

template <typename Container>
void    run(Container &data)
{
    Container small;
    Container big;
    splitArray(data, small, big);
    // print(big, small);
    sortBig(big);
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