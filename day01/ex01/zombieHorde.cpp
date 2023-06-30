#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    zs = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zs[i] = Zombie(name);
    }
    return (zs);
}