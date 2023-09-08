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

int    get_index(std::string in_name)
{
    std::string forms[3] = {"SHRUBBERY CREATION", "ROBOTOMY REQUEST", "PRESIDENTIAL PARDON"};
    for (int j = 0; j < (int)in_name.length(); j++)
    {
        if (std::isalpha(in_name[j]))
            in_name[j] = std::toupper(in_name[j]);
    }
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == in_name)
            return (i);
    }
    return (-1);
}

AForm* Intern::makeForm(std::string f_name, std::string f_target)
{
    int index = get_index(f_name);
    AForm *ptr_arr[3] = {new ShrubberyCreationForm(f_target), new RobotomyRequestForm(f_target), new PresidentialPardonForm(f_target)};
    AForm *ret;

    if (index >= 0)
    {
        ret = ptr_arr[index];
        for (int l = 0;  l < 3; l++)
        {
            if (index != l)
                delete ptr_arr[l];
        }
        std::cout << "Intern creates " << f_name << std::endl;
        return (ret);
    }
    for (int l = 0;  l < 3; l++)
        delete ptr_arr[l];
    std::cout << "The Form not found" << std::endl;
    return (NULL);
}
