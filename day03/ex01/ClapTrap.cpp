#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "BOOT";
    health = 10;
    e_point = 10;
    a_damage = 0;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : name(n)
{
    std::cout << "Constructor called" << std::endl;
    health = 10;
    e_point = 10;
    a_damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
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
        e_point--;
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
    if (e_point > 0 && health > 0)
    {
        e_point--;
        health += amount;
        std::cout << "Get " << amount << " back to health" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (health > 0 || e_point > 0)
    {
        health -= amount;
        std::cout << name << " take damage with " << amount << std::endl;
    }
}