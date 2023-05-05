#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon w)
{
    wp = w;
}

void    HumanB::attack()
{
    std::cout << name << " attacks with their " << wp.getType() << std::endl;
}

HumanB::HumanB()
{
}

HumanB::HumanB(std::string n): name(n)
{
}

HumanB::~HumanB()
{
}