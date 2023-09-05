#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string in_target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm &operator= (const PresidentialPardonForm& src);
    ~PresidentialPardonForm();

    /* *************************** */
    std::string getTarget() const;
    virtual void execute(const Bureaucrat& executor) const;
};



#endif