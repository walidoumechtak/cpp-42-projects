#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AFrom
{
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm &operator= (const ShrubberyCreationForm& src);
        virtual void    execute(Bureaucrat const & executor) const;
        void    trees();
};

#endif