#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& source);
        Cat &operator= (const Cat& source);
        std::string getType() const;
        void    makeSound() const;
        ~Cat();
};

#endif