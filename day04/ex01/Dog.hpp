#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain *d_brain;
    public:
        Dog();
        Dog(const Dog& source);
        Dog &operator= (const Dog& source);
        std::string    getType() const;
        void    makeSound() const;
        void setBrain(Brain *ptr);
        Brain   *getBrain();
        ~Dog();
};

#endif