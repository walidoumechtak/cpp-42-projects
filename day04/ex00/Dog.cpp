#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "[Dog] default Constructor" << std::endl;
}

Dog::Dog(const Dog& source)
{
    *this = source;
    std::cout << "[Dog] Copy Constructor" << std::endl;
}

Dog &Dog::operator= (const Dog& source)
{
    if (this != &source)
    {
        this->type = source.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "[Dog] Distructor" << std::endl;
}

// =========================================

void    Dog::makeSound() const
{
    std::cout << "Dog sound ............." << std::endl;
}

std::string Dog::getType() const
{
    return (type);
}