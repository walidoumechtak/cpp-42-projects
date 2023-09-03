#include "Bureaucrat.hpp"

/* ********** Start canonicla from ********** */
Bureaucrat::Bureaucrat() : name("BOOT"), grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade) : name(in_name)
{
    if (in_grade < 1)
        throw Bureaucrat::GradeTooHighException("You pass the Hiegh grad");
    else if (in_grade > 150)
        throw Bureaucrat::GradeTooLowException("You pass the Low grad");
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
        throw   Bureaucrat::GradeOutOfRange("The Grade is out of range");
    this->grade--;
}

void    Bureaucrat::decGrade()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeOutOfRange("The Grade is out of range");
    this->grade++;
}

std::ostream &operator<< (std::ostream& os, const Bureaucrat& obj)
{
    std::stringstream ss;

    ss << obj.getGrade();
    os << obj.getName() + ", bureaucrat grade " + ss.str();
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

/* ---------- Thirt class ---------- */

Bureaucrat::GradeOutOfRange::GradeOutOfRange(std::string in_msg)
    : msg(in_msg)
{
}

Bureaucrat::GradeOutOfRange::~GradeOutOfRange() throw()
{
}

const char* Bureaucrat::GradeOutOfRange::what() const throw()
{
    return (msg.c_str());
}
