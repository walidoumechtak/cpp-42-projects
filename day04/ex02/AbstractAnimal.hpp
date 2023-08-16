#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Brain.hpp"

class AbstractAnimal
{

    protected:
        std::string type;
    public:
        AbstractAnimal();
        AbstractAnimal(std::string typ);
        AbstractAnimal(const AbstractAnimal& obj);
        AbstractAnimal &operator= (const AbstractAnimal& obj);
        std::string getType() const;
        virtual void    makeSound() const = 0;
        virtual ~AbstractAnimal();
};


#endif