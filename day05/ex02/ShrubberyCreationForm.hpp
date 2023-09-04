#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AFrom
{
    private:

    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm &operator= (const ShrubberyCreationForm& src);
        virtual void    beSigned(const Bureaucrat& source);
        virtual void    execute(Bureaucrat const & executor) const;
        void    trees();
};

#endif