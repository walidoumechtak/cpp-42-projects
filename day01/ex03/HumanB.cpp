#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon *w)
{
    wp = w;
}

void    HumanB::attack()
{
    if (wp != nullptr)
        std::cout << name << " attacks with their " << wp->getType() << std::endl;
}

HumanB::HumanB()
{
}

HumanB::HumanB(std::string n): name(n)
{
    wp = nullptr;
}

HumanB::~HumanB()
{
}