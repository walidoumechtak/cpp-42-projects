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
    char c = std::toupper(f_name[0]);
    char arr[3] = {'S', 'R', 'P'};
    AForm *ptr_arr[3] = {new ShrubberyCreationForm(f_target), new RobotomyRequestForm(f_target), new PresidentialPardonForm(f_target)};
    AForm *ret;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == c)
        {
            ret = ptr_arr[i];
            for (int l = 0;  l < 3; l++)
            {
                if (i != l)
                    delete ptr_arr[l];
            }
            std::cout << "Intern creates " << f_name << std::endl;
            return (ret);
        }
    }
    for (int l = 0;  l < 3; l++)
        delete ptr_arr[l];
    std::cout << "The Form not found" << std::endl;
    return (NULL);
}
