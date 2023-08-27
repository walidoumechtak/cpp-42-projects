#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "[WrongCat] default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal()
{
    *this = source;
    std::cout << "[WrongCat] Copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator= (const WrongCat& source)
{
    if (this != &source)
    {
        this->type = source.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Distructor" << std::endl;
}

// =========================================

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat sound ............." << std::endl;
}

std::string WrongCat::getType() const
{
    return (type);
}