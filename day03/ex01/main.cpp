#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap s1("SCAV");

    s1.attack("walid");
    s1.beRepaired(4);
    s1.takeDamage(2);
    s1.guardGate();
    return (0);
}