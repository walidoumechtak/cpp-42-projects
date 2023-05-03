#include "Zombie.hpp"

int main()
{
    int n = 5;
    Zombie inst = Zombie();
    Zombie *arr = inst.zombieHorde(n, "walid");
    
    for(int i = 0; i < 5; i++)
    {
        arr[i].announce();
    }
}