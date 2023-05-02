#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    Zombie* zooo;

    zooo = new Zombie(name);
    return (zooo);
}