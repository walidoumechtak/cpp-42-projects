#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("President")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string in_target)
    : AForm("PresidentialPardonForm", 25, 5), target(in_target)
{
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src.getFormName(), src.getGradToSign(), src.getGradToExec()), target(src.getTarget())
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}


PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm& src)
{
    if (this != &src)
    {
        this->setSigned(src.getIsSigned());
    }
    return (*this);
}


void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    int grad = executor.getGrade();
    if (grad <= getGradToExec() && getIsSigned() == true)
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
