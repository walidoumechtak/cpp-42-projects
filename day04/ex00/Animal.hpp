#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

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
        ~Animal();
};

#endif