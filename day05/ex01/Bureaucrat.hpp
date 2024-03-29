#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception
            {
                private:
                    std::string msg;
                public:
                    GradeTooHighException(std::string in_msg);
                    ~GradeTooHighException() throw();
                    virtual const char* what() const throw();
            };

            class GradeTooLowException : public std::exception
            {
                private:
                    std::string msg;
                public:
                    GradeTooLowException(std::string in_msg);
                    ~GradeTooLowException() throw();
                    virtual const char* what() const throw();
            };

    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string in_name, int in_grade);
        Bureaucrat(const Bureaucrat& source);
        Bureaucrat& operator= (const Bureaucrat& source);
        ~Bureaucrat();
        int getGrade() const;
        std::string getName() const;
        void    incGrade();
        void    decGrade();
        void    signForm(const Form& source);

       

};

std::ostream& operator<<(std::ostream & os, const Bureaucrat& obj);

#endif