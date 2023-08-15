#include "Brain.hpp"

Brain::Brain()
{
    for (int    i = 0; i < 100; i ++)
        ideas[i] = "Void";
    std::cout << "[Brain] default Constructor" << std::endl;
}

Brain::Brain(const Brain& source)
{
    *this = source;
    std::cout << "[Brain] Copy Constructor" << std::endl;
}

Brain &Brain::operator= (const Brain& source)
{
    if (this != &source)
    {
        for (int    i = 0; i < 100; i ++)
        {
            this->ideas[i] = source.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "[Brain] Distructor" << std::endl;
}


// ===============  Getter and Setter

void    Brain::setBrain(std::string str, int lim)
{
    for (int i = 0; i < lim; i ++)
        ideas[i] = str;
}
