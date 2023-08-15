#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain   *c_brain;
    public:
        Cat();
        Cat(const Cat& source);
        Cat &operator= (const Cat& source);
        std::string getType() const;
        void    makeSound() const;
        Brain   *getBrain();
        void    setBrain(Brain *ptr);
        ~Cat();
};

#endif