#include "HumanA.hpp"

void    HumanA::setWeapon(Weapon w)
{
    wp = w;
}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << wp.getType() << std::endl;
}

HumanA::HumanA(std::string n, Weapon w): name(n), wp(w)
{
}

HumanA::HumanA()
{
}

HumanA::~HumanA()
{
}