#include "Zombie.hpp"

int main(void)
{
    Zombie *zo_in_heap = newZombie("heap");
    randomChump("stack");
    zo_in_heap->announce();
    delete(zo_in_heap);
    return (0);
}