#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie{

private:
    std::string name;

public:
    Zombie();
    Zombie(Zombie *obj);
    Zombie(std::string n);
    ~Zombie();
    void    announce(void) const;
    void    setName(std::string name);
   
};

Zombie* zombieHorde( int N, std::string name );
#endif