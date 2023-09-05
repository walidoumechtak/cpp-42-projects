#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{

    // try
    // {
    //     ShrubberyCreationForm sh1("home");
    //     Bureaucrat b1("walid", 1);
    //     sh1.beSigned(b1);
    //     sh1.execute(b1);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() <<  std::endl;
    // }
    
    std:: cout << "__________________________" << std::endl << std::endl;
    
    // try
    // {
    //     RobotomyRequestForm r1("ROBOT");

    //     Bureaucrat b2("med", 100);
    //     r1.beSigned(b2);
    //     r1.execute(b2);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    
    std:: cout << "__________________________" << std::endl << std::endl;

    try
    {
        PresidentialPardonForm p1("Boos");
        Bureaucrat b3("amine", 4);
        p1.beSigned(b3);
        p1.execute(b3);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}