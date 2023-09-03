#include "Form.hpp"

Form::Form() : form_name("BOOT"), is_signed(false), grad_to_sign(5), grad_to_exec(10)
{
}

Form::Form(const std::string in_name, const int in_grad_sign, const int in_grad_exec)
    : form_name(in_name), is_signed(false), grad_to_sign(in_grad_sign), grad_to_exec(in_grad_exec)
{
    if (grad_to_exec < 1)
        throw Form::GradeTooHighException;
    else if (grad_to_exec > 150)
        throw Form::GradeTooLowException;
    else if (grad_to_sign < 1)
        throw Form::GradeTooHighException;
    else if (grad_to_sign > 150)
        throw Form::GradeTooLowException;
}

Form::Form(const From &source)
{
    *this = source
}

Form &Form::operator= (const Form& source)
{
    if (this != &source)
    {
        this->is_signed = source.is_signed;
    }
    return (*this);
}

Form::~Form()
{
}

/* ---------- End canonical form ---------- */

const std::string Form::getName() const
{
    return (this->form_name);
}

bool    Form::is_signed() const
{
    return (this->is_signed);
}

const int   Form::grad_to_exec() const
{
    return (this->grad_to_exec);
}

const int   Form::grad_to_sign() const
{
    return (this->grad_to_sign);
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    std::stringstream ss;
    std::string result;

    ss << obj.getGrade();
    os << obj.getName() + ", bureaucrat grade " + ss.str();
    return (os);
}

/* ========== start implement class exception ========== */

const char* Form::GradeTooHighException::what() const throw()
{
    return ("You pass the High grade");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("You pass the Low grade");
}
