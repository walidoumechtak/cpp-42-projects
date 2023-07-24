#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    cout << "default [ScavTrap] constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n, int h, int e_p, int a_d)  : name(n), health(h), e_point(e_p), a_damage(a_d)
{
}

ScavTrap::~ScavTrap()
{
    cout << "[ScavTrap] destrucotr called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
    std::cout << "Copy [ScavTrap] constructor called" << std::endl;
    this->name     = obj.name;
    this->health   = obj.health;
    this->e_point  = obj.e_point;
    this->a_damage = obj.a_damage;
}

ScavTrap &ScavTrap::operator= (const ScavTrap& obj)
{
    std::cout << "Copy [ScavTrap] assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name     = obj.name;
        this->health   = obj.health;
        this->e_point  = obj.e_point;
        this->a_damage = obj.a_damage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    
}