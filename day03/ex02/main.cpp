#include "FragTrap.hpp"

int main(void)
{
    FragTrap frag("FRAG");

    frag.attack("My enemy");
    frag.attack("My enemy");
    frag.beRepaired(50);
    frag.takeDamage(200);
    frag.attack("My enemy");
    frag.highFivesGuys();

    return (0);
}