#include "ClapTrap.hpp"

ClapTrap::ClapTap()
{
}

ClapTrap::ClapTap(std::string n, int h, int e_p, int a_d) : name(n), health(h), e_point(e_p), a_damage(a_d)
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTap(const ClapTrap& obj)
{
    this->name     = obj.name;
    this->health   = obj.health;
    this->e_point  = obj.e_point;
    this->a_damage = obj.a_damage;
}

ClapTrap &ClapTrap::operator= (const ClapTrap& obj)
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

/* ==============  start member function of subject ================= */

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap ";
    std::cout << name;
    std::cout << " attakcs ";
    std::cout << target;
    std::cout << ", causing ";
    std::cout << a_damage;
    std::cout << " points of damage!" << std::endl;
}