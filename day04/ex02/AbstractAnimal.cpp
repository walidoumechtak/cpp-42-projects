#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal()
{
    std:: cout << "[AbstractAnimal] default constructor" << std::endl;
    type = "";
}

AbstractAnimal::AbstractAnimal(std::string ty) : type(ty)
{
    std:: cout << "[AbstractAnimal] Constructor" << std::endl;    
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal& obj)
{
    *this = obj;
    std:: cout << "[AbstractAnimal] Destructor" << std::endl;    

}

AbstractAnimal &AbstractAnimal::operator= (const AbstractAnimal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

AbstractAnimal::~AbstractAnimal()
{
    std:: cout << "[AbstractAnimal] Destructor" << std::endl;    
}

// ===========================================================

std::string AbstractAnimal::getType() const
{
    return (type);
}