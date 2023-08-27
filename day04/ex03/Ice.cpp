#include "Ice.hpp"

/* ========== Start canonical form ==========*/
Ice::Ice()
{
    type = "ice";
    std::cout << "[Ice] Default Constructor called" << std::endl;
}

Ice::Ice(const Ice& source) : AMateria()
{
    std::cout << "[Ice] Copy constructor called" << std::endl;
    *this = source;
}

Ice &Ice::operator= (const Ice& source)
{
    if (this != &source)
    {
        this->type = source.getType();
    }
    return (*this);
}

Ice::~Ice()
{
    std::cout << "[Ice] Destructor called" << std::endl;
}
/* ========== End canonical form ==========*/

AMateria* Ice::clone() const
{
    AMateria* new_obj = new Ice();
    return (new_obj);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
