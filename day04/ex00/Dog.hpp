#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& source);
        Dog &operator= (const Dog& source);
        std::string    getType() const;
        void    makeSound() const;
        ~Dog();
};

#endif