#include "Animal.hpp"

Animal::Animal()
{
    std:: cout << "[Animal] default constructor" << std::endl;
    type = "";
}

Animal::Animal(std::string ty) : type(ty)
{
    std:: cout << "[Animal] Constructor" << std::endl;    
}

Animal::Animal(const Animal& obj)
{
    std:: cout << "[Animal] Copy Constructor" << std::endl;
    *this = obj;
}

Animal &Animal::operator= (const Animal& obj)
{
    std::cout << "[Animal] copy assignement operator" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std:: cout << "[Animal] Destructor" << std::endl;    
}

// ===========================================================

void    Animal::makeSound() const
{
    std::cout << "I am just an animal" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}