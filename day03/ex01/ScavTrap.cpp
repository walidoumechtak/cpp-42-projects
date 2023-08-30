#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->health = 100;
    this->e_point = 50;
    this->a_damage = 20;
    std::cout << "default [ScavTrap] constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n){
    this->health = 100;
    this->e_point = 50;
    this->a_damage = 20;
    std::cout << "[ScavTrap] constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap] destrucotr called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "Copy [ScavTrap] constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator= (const ScavTrap& obj)
{
    std::cout << "Copy [ScavTrap] assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->a_damage = obj.a_damage;
        this->e_point = obj.e_point;
        this->health = health;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (health > 0 && e_point > 0)
        std::cout << "[ScavTrap] " << name << " attack " << target << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}