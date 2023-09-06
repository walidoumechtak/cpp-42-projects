#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string in_target)
    : AForm("RobotomyRequestForm", 72, 45), target(in_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src.getFormName(), src.getGradToSign(), src.getGradToExec()), target(src.getTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm& src)
{
    if (this != &src)
    {
        this->setSigned(src.getIsSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    int grad = executor.getGrade();
    if (grad < getGradToExec() && getIsSigned() == true)
    {
        // Seed the random number generator with the current time
        std::srand(std::time(0));
        // Generate and print a random number between 1 and 10
        int randomNumber = (std::rand() % 100) + 1;
        std::cout << randomNumber << std::endl;
        if (randomNumber >= 50)
            std::cout << target << " has been robotomized successfully 50% of the tim" << std::endl;
        else
            std::cout << "the robotomy failed." << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
