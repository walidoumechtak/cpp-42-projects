#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

// class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    /* start canonical form */
    AMateria();
    AMateria(std::string in_type);
    AMateria(const AMateria& source);
    AMateria &operator= (const AMateria& source);
    virtual ~AMateria();
    /* end canonical form */

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif