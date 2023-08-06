#include <iostream>
#include <string>

int main()
{
    int *arr = new int[0];

    delete [] arr;

    arr = new int[100];

    while (1);
}