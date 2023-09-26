#include "Bureaucrat.hpp"

/* ********** Start canonicla from ********** */
Bureaucrat::Bureaucrat() : name("BOOT"), grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade) : name(in_name)
{
    if (in_grade < 1)
        throw Bureaucrat::GradeTooHighException("Hiegh grade value");
    else if (in_grade > 150)
        throw Bureaucrat::GradeTooLowException("Low grad value");
    this->grade = in_grade;
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& source)
{
    *this = source;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source)
{
    if (this != &source)
    {
        this->grade = source.grade;
    }
    return (*this);
}
/* ********** End canonicla from ********** */

int Bureaucrat::getGrade() const
{
    return (grade);
}

std::string Bureaucrat::getName() const
{
    return (name);
}

void    Bureaucrat::incGrade()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException("Hiegh grade value");
    this->grade--;
}

void    Bureaucrat::decGrade()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException("Low grade value");
    this->grade++;
}

std::ostream &operator<< (std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (os);
}

/* ==================== Exception classes ==================== */

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string in_msg)
    : msg(in_msg)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (msg.c_str());
}

/* ---------- Second class ---------- */

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string in_msg)
    : msg(in_msg)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (msg.c_str());
}

void Bureaucrat::signForm(const AForm& source)
{
    bool is_signed = source.getIsSigned();
    if (is_signed == true)
        std::cout << this->name << " signed " << source.getFormName() << std::endl;
    else
        std::cout << this->name << " couldn't sign " << source.getFormName() << " because ...., i think i forget" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (grade <= form.getGradToExec() && form.getIsSigned())
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getFormName() << std::endl;
    }
    else
        std::cout << "Couldn't execute the form ):" << std::endl;
}
