#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "Boot";
    health = 10;
    e_point = 10;
    a_damage = 0;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : name(n)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->name     = obj.name;
    this->health   = obj.health;
    this->e_point  = obj.e_point;
    this->a_damage = obj.a_damage;
}

ClapTrap &ClapTrap::operator= (const ClapTrap& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name     = obj.name;
        this->health   = obj.health;
        this->e_point  = obj.e_point;
        this->a_damage = obj.a_damage;
    }
    return (*this);
}

/* ==============  start member function of subject ================= */

void ClapTrap::attack(const std::string& target)
{
    if (health > 0 && e_point > 0)
    {
        health -= a_damage;
        std::cout << "ClapTrap ";
        std::cout << name;
        std::cout << " attakcs ";
        std::cout << target;
        std::cout << ", causing ";
        std::cout << a_damage;
        std::cout << " points of damage!" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (e_point > 0)
    {
        health += amount;
        std::cout << "Get " << amount << " back to health" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (health > 0)
    {
        std::cout << name << " change take damage with " << amount << std::endl;
        a_damage = amount;
    }
}