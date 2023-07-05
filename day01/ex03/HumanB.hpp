#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{

private:
    std::string name;
    Weapon  *wp;

public:
    void    attack();
    void    setWeapon(Weapon *w);
    HumanB();
    HumanB(std::string n);
    ~HumanB();
};

#endif
