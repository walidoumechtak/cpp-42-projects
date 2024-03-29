#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "[Cat] default Constructor" << std::endl;
}

Cat::Cat(const Cat& source) : Animal()
{
    *this = source;
    std::cout << "[Cat] Copy Constructor" << std::endl;
}

Cat &Cat::operator= (const Cat& source)
{
    std::cout << "[Cat] copy assignement operator" << std::endl;
    if (this != &source)
    {
        this->type = source.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "[Cat] Distructor" << std::endl;
}

// =========================================

void    Cat::makeSound() const
{
    std::cout << " ----/\\---- Cat sound ----/\\---- " << std::endl;
}

std::string Cat::getType() const
{
    return (type);
}