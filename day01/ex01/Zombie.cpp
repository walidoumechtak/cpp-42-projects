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
<<<<<<< HEAD
    
=======
   // std::cout << "Destructor called" << std::endl;
    delete[] zs;
>>>>>>> 721ae729fbc494ff207384adf8182e7f7991af98
}
