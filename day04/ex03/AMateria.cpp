#include "AMateria.hpp"

/* ========== Start canonical form ========== */
AMateria::AMateria()
{
    std::cout << "[AMateria] Default constructr called" << std::endl;
}

AMateria::AMateria(std::string in_type) : type(in_type)
{
    std::cout << "[AMateria] Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& source)
{
    std::cout << "[AMateria] Copy constructor called" << std::endl;
    *this = source;
}

AMateria &AMateria::operator= (const AMateria& source)
{
    if (this != &source)
        this->type = source.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "[AMateria] Destructor called" << std::endl;
}
/* ========== end canonical form ========== */

std::string const &AMateria::getType() const
{
    return (type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "Default AMateira message use() with name: " << target.getName() << std::endl;
}