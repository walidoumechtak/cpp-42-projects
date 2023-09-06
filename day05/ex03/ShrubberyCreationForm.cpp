#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("TAR_BOOT")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string tar) 
    : AForm("ShrubberyCreationForm", 145, 137), target(tar)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src.getFormName(), src.getGradToSign(), src.getGradToExec()), target(src.getTarget())
{
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm& src)
{
    if (this != &src)
    {
        this->setSigned(src.getIsSigned());
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // signed and the grad is good enough to execut it
    int grad = executor.getGrade();
    if (grad < getGradToExec() && getIsSigned() == true)
    {
        std::string file_name = target + "_shrubbery";
        std::fstream outfile(file_name.c_str(), std::ios::out);
        
        if (outfile.is_open())
        {
            outfile << "                   ^"                 << std::endl;
            outfile << "                  ^^^"                << std::endl;
            outfile << "                 ^^^^^"               << std::endl;
            outfile << "                ^^^^^^^"              << std::endl;
            outfile << "               ^^^^^^^^^"             << std::endl;
            outfile << "              ^^^^^^^^^^^"            << std::endl;
            outfile << "             ^^^^^^^^^^^^^"           << std::endl;
            outfile << "            ^^^^^^^^^^^^^^^"          << std::endl;
            outfile << "           ^^^^^^^^^^^^^^^^^"         << std::endl;
            outfile << "          ^^^^^^^^^^^^^^^^^^^"        << std::endl;
            outfile << "         ^^^^^^^^^^^^^^^^^^^^^"       << std::endl;
            outfile << "               ||||||||||"            << std::endl;
            outfile << "               ||||||||||"            << std::endl;
   
        }
        else
            std::cout << "couldn't open the file for _shrubbery" << std::endl;
    }
    else
        throw AForm::GradeTooHighException();
}
