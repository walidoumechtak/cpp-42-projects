#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap c1;
    ScavTrap s1("the Scav", 100, 50, 20);

    c1.attack("monster");
    s1.attack("walid");
    s1.guardGate();
    return (0);
}