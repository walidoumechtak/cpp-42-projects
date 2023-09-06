#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    public:
        Intern(/* args */);
        Intern(const Intern& src);
        Intern &operator= (const Intern& src);
        ~Intern();
        
        /* ================================== */

        AForm*    makeForm(std::string f_name, std::string f_target);
};

#endif