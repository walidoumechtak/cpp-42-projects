#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& source);
        WrongCat &operator= (const WrongCat& source);
        std::string getType() const;
        void    makeSound() const;
        ~WrongCat();
};

#endif