#include "Zombie.hpp"

void    Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::Zombie()
{
}

Zombie::Zombie(std::string n) : name(n)
{
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " die!!" << std::endl;
}
