#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap s1("SCAV");
    ScavTrap s2(s1);
    // s1.attack("walid");
    // s1.beRepaired(4);
    // s1.takeDamage(2);
    // s1.guardGate();
    
    s2.attack("walid");
    s2.takeDamage(100);
    s2.attack("asdf");

    return (0);
}