#include "Bureaucrat.hpp"

int main(void)
{

    try
    {
        Bureaucrat b1("walid", 5);
        Form f1("Certificat", 10, 55);
        std::cout << f1 << std::endl;
        b1.signForm();
        f1.beSigned(b1);
        std::cout << f1 << std::endl;
        b1.signForm();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
    
    std:: cout << "__________________________" << std::endl << std::endl;
    
    try
    {
        Bureaucrat b2("med", 10);
        Form f1("Off Form", 0, 100);
        f1.beSigned(b2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    
}