#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Defautl [FragTrap] constructor called" << std::endl;
    this->name = "Boot";
    this->health = 100;
    this->e_point = 100;
    this->a_damage = 30;
}

FragTrap::FragTrap(std::string nm) : ClapTrap(nm)
{
    std::cout << "[FragTrap] constructor called" << std::endl;
    health = 100;
    e_point = 100;
    a_damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj)
{
    *this = obj;
    std::cout << "Copy [FragTrap] constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] distructor called" << std::endl;
}

FragTrap &FragTrap::operator= (const FragTrap& obj)
{
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "lets give a height five   \\o/" << std::endl;
}