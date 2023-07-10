#include "Zombie.hpp"

int main()
{
    int n = 5;

    Zombie *arr = zombieHorde(n, "walid");
    for(int i = 0; i < 5; i++)
    {
        arr[i].announce();
    }
    delete[] arr;
}