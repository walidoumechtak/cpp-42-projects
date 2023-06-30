#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::Zombie()
{
}

Zombie::Zombie(std::string n) : name(n)
{
}

Zombie::~Zombie()
{
    delete[] zs;
}
