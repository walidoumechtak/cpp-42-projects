#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& source);
    Ice &operator= (const Ice& source);
    ~Ice();
    virtual AMateria* clone() const; // overided function from its base class AMateria
    virtual void use(ICharacter& target);
};

#endif