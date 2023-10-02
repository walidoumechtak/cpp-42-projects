#include "iter.hpp"
#include <iostream>
#include <string>


void    increment(int &a)
{
    a++;
}

int main(void)
{
    int size = 5;
    int arr[5] = {0};

    iter(arr, size, &increment);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;
}