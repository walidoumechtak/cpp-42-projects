#include "ClapTrap.hpp"

int main(void)
{
    // ClapTrap c1;

    // c1.attack("monster");
    // c1.takeDamage(5);
    // c1.takeDamage(5);
    // c1.takeDamage(5);
    // // here the boot will not do anything
    // c1.beRepaired(5);
    // c1.attack("monster");


    // =================================


    ClapTrap obj("walid");

    obj.attack("Player");
    obj.takeDamage(5);
    obj.beRepaired(5);
    obj.takeDamage(0);
    
    return (0);
}