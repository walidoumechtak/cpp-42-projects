#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::Zombie()
{
   // std::cout << "Consturcor called" << std::endl;
}

Zombie::Zombie(std::string n) : name(n)
{
   // std::cout << "Consturcor called" << std::endl;
}

Zombie::~Zombie()
{
   // std::cout << "Destructor called" << std::endl;
    delete[] zs;
}
