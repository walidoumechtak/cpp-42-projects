#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : form_name("BOOT"), is_signed(false), grad_to_sign(5), grad_to_exec(10)
{
}

Form::Form(const std::string in_name, const int in_grad_sign, const int in_grad_exec)
    : form_name(in_name), is_signed(false), grad_to_sign(in_grad_sign), grad_to_exec(in_grad_exec)
{
    if (grad_to_exec < 1)
        throw Form::GradeTooHighException();
    else if (grad_to_exec > 150)
        throw Form::GradeTooLowException();
    else if (grad_to_sign < 1)
        throw Form::GradeTooHighException();
    else if (grad_to_sign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &source) 
    : form_name(source.form_name) ,grad_to_sign(source.grad_to_sign), grad_to_exec(source.grad_to_exec)
{
    this->is_signed = source.is_signed;
}

Form &Form::operator= (const Form& source)
{
    if (this != &source)
    {
        this->is_signed = source.is_signed;
        *const_cast<std::string*> (&this->form_name) = source.form_name;
        *const_cast<int*> (&this->grad_to_exec) = source.grad_to_exec;
        *const_cast<int*> (&this->grad_to_sign) = source.grad_to_sign;
    }
    return (*this);
}

Form::~Form()
{
}

/* ---------- End canonical form ---------- */

const std::string Form::getFormName() const
{
    return (this->form_name);
}

bool Form::getIsSigned() const
{
    return is_signed;
}

int Form::getGradToSign() const
{
    return grad_to_sign;
}

int   Form::getGradToExec() const
{
    return (this->grad_to_exec);
}

void Form::beSigned(const Bureaucrat &source)
{
    int gr = source.getGrade();
    if (gr <= grad_to_sign)
    {
        this->is_signed = true;
    }
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &_cout, const Form &obj)
{
    std::string is_sign;

    if (obj.getIsSigned() == true) 
        is_sign = "signed";
    else
        is_sign = "not signed";
    _cout << "The form: " << obj.getFormName() << " has grade to sign: " << obj.getGradToSign() << ", and grade to exec: " << obj.getGradToExec() << ", the state is: " << is_sign;
    return (_cout);
}

/* ========== start implement class exception ========== */

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Hiegh grade value");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Low grade value");
}
