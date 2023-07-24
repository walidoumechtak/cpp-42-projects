#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
    
public:
    using ClapTrap::ClapTrap;

    ScavTrap();
    ScavTrap(std::string n, int h, int e_p, int a_d);
    ScavTrap(const ScavTrap& obj);
    ScavTrap &operator= (const ScavTrap& obj);
    ~ScavTrap();
    void    guardGate();
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif /* SCAVTRAP_H */