#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string name;
    int health;
    int e_point;
    int a_damage;

public:
    ClapTrap();
    ClapTrap(std::string n);
    ClapTrap(const ClapTrap& obj);
    ~ClapTrap();
    ClapTrap &operator= (const ClapTrap& obj);
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif