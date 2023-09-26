#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("walid", 5);
        std::cout << b1 << std::endl;
        b1.incGrade();
        b1.incGrade();
        std:: cout << b1 << std::endl;
        b1.decGrade();
        std:: cout << b1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std:: cout << "__________________________" << std::endl << std::endl;

    try
    {
        Bureaucrat b2("Low", 200);
        std::cout << b2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
    std:: cout << "__________________________" << std::endl << std::endl;

    try
    {
        Bureaucrat b3("Hiegh", 0);
        std::cout << b3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std:: cout << "__________________________" << std::endl << std::endl;
    try
    {
        Bureaucrat b4("OutRange", 2);
        b4.incGrade();
        b4.incGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}