#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "default [ScavTrap] constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n, int h, int e_p, int a_d) : ClapTrap(n, h,  e_p,  a_d){
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
        ClapTrap::operator=(obj);
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap attack " << target << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gate keeper mode" << std::endl;
}