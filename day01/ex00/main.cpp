#include "Zombie.hpp"

int main()
{
    Zombie zo = Zombie();
    Zombie *zo_in_heap = zo.newZombie("heap");
    
    zo.randomChump("stack");
    zo_in_heap->announce();
    return (0);
}