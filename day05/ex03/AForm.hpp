#ifndef AFORM_HPP
#define AFORM_HPP

// #include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>


class Bureaucrat;

class AForm
{
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string form_name;
        bool    is_signed;
        const int grad_to_sign;
        const int grad_to_exec;

    public:
        AForm();
        AForm(const std::string in_name, const int in_grad_sign, const int in_grad_exec);
        AForm(const AForm& source);
        AForm &operator = (const AForm& source);
        virtual ~AForm();
        const   std::string getFormName() const;
        bool    getIsSigned() const;
        int   getGradToSign() const;
        int   getGradToExec() const;
        void    beSigned(const Bureaucrat& source);
        virtual void    execute(Bureaucrat const & executor) const = 0;
        void    setSigned(int sign);
};

std::ostream &operator<< (std::ostream& os, const AForm& obj);

#endif