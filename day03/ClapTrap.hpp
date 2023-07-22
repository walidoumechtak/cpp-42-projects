#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        int health   = 10;
        int e_point  = 10;
        int a_damage = 0;
    public:
        ClapTrap();
        ClapTrap(std::string n, int h, int e_p, int a_d);
        ClapTap(const ClapTrap& obj);
        ~ClapTrap();
        ClapTrap &operator= (const ClapTrap& obj);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif