#ifndef FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
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
        Form();
        Form(const std::string in_name, const int in_grad_sign, const int in_grad_exec);
        Form(const Form& source);
        Form &operator = (const Form& source);
        ~Form();
        const   std::string getFormName() const;
        bool    getIsSigned() const;
        int   getGradToSign() const;
        int   getGradToExec() const;
        void    beSigned(const Bureaucrat& source);
};

std::ostream &operator<< (std::ostream& os, const Form& obj);

#endif