#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string tar);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm &operator= (const ShrubberyCreationForm& src);
        virtual void    execute(Bureaucrat const & executor) const;
};

#endif