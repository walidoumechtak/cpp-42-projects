#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Form : public Bureaucrat
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
        Form(const From& source);
        Form &operator = (const Form& source);
        ~Form();
        const   std::string getName() const;
        bool    getIsSigned();
        const int   grad_to_sign() const;
        const int   grad_to_exec() const;
};

std::ostream &operator<< (std::ostream& os, const Form& obj);

#endif