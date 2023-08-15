#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Brain.hpp"

class Animal
{

    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string typ);
        Animal(const Animal& obj);
        Animal &operator= (const Animal& obj);
        std::string getType() const;
        virtual void    makeSound() const;
        virtual ~Animal();
};


#endif