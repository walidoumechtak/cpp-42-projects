#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon *w)
{
    wp = w;
}

void    HumanB::attack()
{
    if (wp != 0)
        std::cout << name << " attacks with their " << wp->getType() << std::endl;
}

HumanB::HumanB()
{
}

HumanB::HumanB(std::string n): name(n)
{
    wp = 0;
}

HumanB::~HumanB()
{
}