#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal
{

    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string typ);
        WrongAnimal(const WrongAnimal& obj);
        WrongAnimal &operator= (const WrongAnimal& obj);
        std::string getType() const;
        void    makeSound() const;
        ~WrongAnimal();
};


#endif