#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "Default [DiamondTrap] constructor called" << std::endl;
    this->name = "boot";
    this->health = FragTrap::health;
    this->e_point = ScavTrap::e_point;
    this->a_damage = FragTrap::a_damage;
}

DiamondTrap::DiamondTrap(std::string iname) : ClapTrap(iname + "_clap_name")
{
    std::cout << "[DiamondTrap] constructor called" << std::endl;
    this->health = FragTrap::health;
    this->e_point = ScavTrap::e_point;
    this->a_damage = FragTrap::a_damage;
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
        this->name     = obj.name;
        this->health   = obj.health;
        this->e_point  = obj.e_point;
        this->a_damage = obj.a_damage;
    }
    return (*this);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << this->name << " and the clapTrap name is " << name << std::endl;
}