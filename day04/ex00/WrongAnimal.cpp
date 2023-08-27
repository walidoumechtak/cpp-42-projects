#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std:: cout << "[WrongAnimal] default constructor" << std::endl;
    type = "";
}

WrongAnimal::WrongAnimal(std::string ty) : type(ty)
{
    std:: cout << "[WrongAnimal] Constructor" << std::endl;    
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    *this = obj;
    std:: cout << "[WrongAnimal] Destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator= (const WrongAnimal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std:: cout << "[WrongAnimal] Destructor" << std::endl;    
}



// ===========================================================

void    WrongAnimal::makeSound() const
{
    std::cout << "I am just a WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}