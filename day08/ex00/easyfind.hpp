#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>

template <typename T>
int easyfind(T container, int target)
{
    typename T::iterator it = find(container.begin(), container.end(), target);

    if (it != container.end())
    {
        std::cout << "The target found: " << *it << std::endl;
        return *it;
    }
    else
        throw std::runtime_error("Element not found");
}

#endif