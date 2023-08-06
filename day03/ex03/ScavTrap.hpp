#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string n);
        ScavTrap(const ScavTrap& obj);
        ScavTrap &operator= (const ScavTrap& obj);
        ~ScavTrap();
        void    guardGate();
        void    attack(const std::string& target);
};

#endif /* SCAVTRAP_H */