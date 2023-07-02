#include "Weapon.hpp"

std::string Weapon::getType() const
{
    return (type);
}

void    Weapon::setType(std::string T)
{
    type = T;
}

Weapon::Weapon(std::string w): type(w)
{
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}