#include "Brain.hpp"

Brain::Brain()
{
    for (int    i = 0; i < 100; i ++)
        ideas[i] = "...Void...";
    std::cout << "[Brain] default Constructor" << std::endl;
}

Brain::Brain(const Brain& source)
{
    std::cout << "[Brain] Copy Constructor" << std::endl;
    *this = source;
}

Brain &Brain::operator= (const Brain& source)
{
    std::cout << "[Brain] Copy assignement called" << std::endl;
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

std::string *Brain::getIdeas()
{
    return (ideas);
}

void    Brain::setIdeas(std::string str, int lim)
{
    std::cout << "Set ideas called" << std::endl;
    for (int i = 0; i < lim; i ++)
        ideas[i] = str;
}
