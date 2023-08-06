#include "Zombie.hpp"

int main()
{
    int n = 5;
    Zombie *arr = zombieHorde(n, "walid");
    
    for(int i = 0; i < n; i++)
    {
        arr[i].announce();
    }
    delete[] arr;
}