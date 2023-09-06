#include "Intern.hpp"
#include <cctype>

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    *this = src;
}

Intern &Intern::operator= (const Intern& src)
{
    if (this != &src)
    {
        // ...........
    }
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string f_name, std::string f_target)
{
    AForm *newAForm;
    char c = std::toupper(f_name[0]);
    char arr[3] = {'S', 'R', 'P'};

    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == c)
        {    
            std::cout << "Found it" << std::endl;
            newAForm = new ShrubberyCreationForm(f_target);
            return (newAForm);
        }
    }
    std::cout << "The Form not found" << std::endl;
    return (NULL);
}
