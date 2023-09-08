#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void    prev_test()
{
  try
    {
        ShrubberyCreationForm sh1("home");
        std::cout << "the shrubery has been apeared !" << std::endl;
        Bureaucrat b1("walid", 1);
        sh1.beSigned(b1);
        b1.executeForm(sh1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
    
    std:: cout << "__________________________" << std::endl << std::endl;
    
    try
    {
        RobotomyRequestForm r1("ROBOT");

        Bureaucrat b2("med", 100);
        r1.beSigned(b2);
        b2.executeForm(r1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std:: cout << "__________________________" << std::endl << std::endl;

    try
    {
        PresidentialPardonForm p1("Boos");
        Bureaucrat b3("amine", 4);
        p1.beSigned(b3);
        b3.executeForm(p1);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main(void)
{

    AForm* rrf;
    Intern myIntern;

    rrf = myIntern.makeForm("robotomy request", "walid");
    if (rrf)
    {
        try
        {
            Bureaucrat b1("amine", 7);
            rrf->beSigned(b1);
            b1.executeForm(*rrf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete rrf;  
    }
    
    /* ================================================================================*/

    rrf = myIntern.makeForm("Shrubbery Creation", "walid");
    if (rrf)
    {
        try
        {
            Bureaucrat b2("walid", 1);
            rrf->beSigned(b2);
            b2.executeForm(*rrf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete rrf;
    }

    /* ================================================================================*/
    
    rrf = myIntern.makeForm("Presidential Pardon", "walid");
    if (rrf)
    {
        try
        {
            Bureaucrat b3("khalid", 4);
            rrf->beSigned(b3);
            b3.executeForm(*rrf);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete rrf;
    }
}