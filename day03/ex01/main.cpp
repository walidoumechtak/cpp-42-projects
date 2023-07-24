#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap c1;

    c1.attack("monster");
    c1.beRepaired(5);
    c1.takeDamage(5);
    c1.attack("monster");
    return (0);
}