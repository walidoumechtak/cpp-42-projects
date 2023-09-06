#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string in_target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        RobotomyRequestForm &operator= (const RobotomyRequestForm & src);
        ~RobotomyRequestForm();

        /* ********************** */
        std::string getTarget() const;
        virtual void    execute(Bureaucrat const & executor) const;

};


#endif