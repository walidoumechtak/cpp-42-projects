#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "[Cat] default Constructor" << std::endl;
    c_brain = new Brain();
}

Cat::Cat(const Cat& source) : Animal()
{
    std::cout << "[Cat] Copy Constructor" << std::endl;
    *this = source;
}

Cat &Cat::operator= (const Cat& source)
{
    std::cout << "[Cat] Copy assignement" << std::endl;
    if (this != &source)
    {
        this->type = source.type;
        // this->c_brain = source.c_brain; //this line is a shallow copy
        this->c_brain = new Brain();       // this line in a deep copy
        std::string *in = source.c_brain->getIdeas();
        std::string *out = this->c_brain->getIdeas();
        for (int i = 0; i < 100; i++)
            out[i] = in[i];
    }
    return (*this);
}

Cat::~Cat()
{
    delete  c_brain;
    std::cout << "[Cat] Distructor" << std::endl;
}

// =========================================

void    Cat::makeSound() const
{
    std::cout << "Cat sound ..... " << std::endl;
}

std::string Cat::getType() const
{
    return (type);
}

// ============= get brain and set brain

Brain   *Cat::getBrain()
{
    return (c_brain);
}

void    Cat::setBrain(Brain *ptr)
{
    c_brain = ptr;
}