#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::Zombie() : name("walo")
{
}

Zombie::Zombie(std::string n) : name(n)
{
}

Zombie::~Zombie()
{
    std::cout << "good by " << name << std::endl;
}
