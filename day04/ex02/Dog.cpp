#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "[Dog] default Constructor" << std::endl;
    type = "Dog";
    d_brain = new Brain();
}

Dog::Dog(const Dog& source) : AbstractAnimal()
{
    std::cout << "[Dog] Copy Constructor" << std::endl;
    *this = source;
}

Dog &Dog::operator= (const Dog& source)
{
    std::cout << "[Dog] Copy assignment Constructor" << std::endl;
    if (this != &source)
    {
        this->type = source.type;
        this->d_brain = new Brain();
    }
    return (*this);
}

Dog::~Dog()
{
    delete  d_brain;
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


// =============== getter and setter of the brain pointer =============

Brain   *Dog::getBrain()
{
    return (this->d_brain);
}


void    Dog::setBrain(Brain *ptr)
{
    this->d_brain = ptr;
}