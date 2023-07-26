#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    
public:
    public:
        ScavTrap();
        ScavTrap(std::string n, int h, int e_p, int a_d);
        ScavTrap(const ScavTrap& obj);
        ScavTrap &operator= (const ScavTrap& obj);
        ~ScavTrap();
        void    guardGate();
        void    attack(const std::string& target);
};

#endif /* SCAVTRAP_H */