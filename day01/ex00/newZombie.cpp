#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    z = new Zombie(name);
    return (z);
}