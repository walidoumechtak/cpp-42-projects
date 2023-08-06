#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "Default [DiamondTrap] constructor called" << std::endl;
    ScavTrap::health = FragTrap::health;
    ScavTrap::a_damage = FragTrap::a_damage;
}

DiamondTrap::DiamondTrap(std::string iname) : name(iname)
{
    std::cout << "[DiamondTrap] constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
    *this = obj;
    std::cout << "[DiamondTrap] copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator==(const DiamondTrap &obj)
{
    if (this != &obj)
    {
        ScavTrap::operator= (obj);
    }
    return (*this);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << this->name << " and the clapTrap name is " << ScavTrap::name << std::endl;
}