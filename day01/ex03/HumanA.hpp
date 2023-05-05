#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA{

private:
    std::string name;
    Weapon  wp;

public:
    void    attack();
    void    setWeapon(Weapon w);
    HumanA();
    HumanA(std::string n, Weapon w);
    ~HumanA();
};

#endif