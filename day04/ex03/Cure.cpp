#include "Cure.hpp"

/* ========== Start canonical form ========== */
Cure::Cure()
{
    type = "cure";
    std::cout << "[Cure] Default construcotr called" << std::endl;
}

Cure::Cure(const Cure& source) : AMateria()
{
    std::cout << "[Cure] Copy construcotr called" << std::endl;
    *this = source;
}

Cure &Cure::operator= (const Cure& source)
{
    if (this != &source)
    {
        this->type = source.getType();
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout << "[Cure] Destructor called" << std::endl;
}
/* ========== End canonical form ========== */

AMateria* Cure::clone() const
{
    AMateria *new_obj = new Cure();
    return (new_obj);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}