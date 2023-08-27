#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    AMateria *arr[4];
    std::string name;
    AMateria *temp;
    int cpt;

public:
    Character();
    Character(std::string in_name);
    Character(const Character& source);
    Character &operator= (const Character& source);
    virtual ~Character();

    // Start override all the virtual function of the interface ICharacter
    virtual std::string const& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif