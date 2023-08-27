#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure& source);
    Cure &operator= (const Cure& source);
    ~Cure();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif