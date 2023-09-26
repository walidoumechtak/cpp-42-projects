#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : form_name("BOOT"), is_signed(false), grad_to_sign(5), grad_to_exec(10)
{
}

AForm::AForm(const std::string in_name, const int in_grad_sign, const int in_grad_exec)
    : form_name(in_name), is_signed(false), grad_to_sign(in_grad_sign), grad_to_exec(in_grad_exec)
{
    if (grad_to_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grad_to_exec > 150)
        throw AForm::GradeTooLowException();
    else if (grad_to_sign < 1)
        throw AForm::GradeTooHighException();
    else if (grad_to_sign > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &source) 
    :form_name(source.form_name), grad_to_sign(source.grad_to_sign), grad_to_exec(source.grad_to_exec)
{
    this->is_signed = source.is_signed;
}

AForm &AForm::operator= (const AForm& source)
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

AForm::~AForm()
{
}

/* ---------- End canonical Aform ---------- */

const std::string AForm::getFormName() const
{
    return (this->form_name);
}

bool AForm::getIsSigned() const
{
    return is_signed;
}

int AForm::getGradToSign() const
{
    return grad_to_sign;
}

int   AForm::getGradToExec() const
{
    return (this->grad_to_exec);
}

void AForm::beSigned(const Bureaucrat &source)
{
    int gr = source.getGrade();
    if (gr <= grad_to_sign)
    {
        this->is_signed = true;
    }
    else
        throw AForm::GradeTooLowException();
}

void AForm::setSigned(int sign)
{
    this->is_signed = sign;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    std::string is_sign;

    if (obj.getIsSigned() == true) 
        is_sign = "signed";
    else
        is_sign = "not signed";
    os << "The form: " << obj.getFormName() << " has grade to sign: " << obj.getGradToSign() << ", and grade to exec: " << obj.getGradToExec() << " and the state is: " << is_sign;
    return (os);
}

/* ========== start implement class exception ========== */

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Hiegh grade value");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Low grade value");
}
