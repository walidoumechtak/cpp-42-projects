#include "Bureaucrat.hpp"

int main(void)
{

    try
    {
        Bureaucrat b1("walid", 5);
        Form f1("Cer1", 10, 55);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        f1.beSigned(b1);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
    
    std:: cout << "__________________________" << std::endl << std::endl;
    
    try
    {
        // in this case the form has a grad to sign too heigh so an exception occure
        Bureaucrat b2("med", 10);
        Form f2("Cer2", 0, 100);
        f2.beSigned(b2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std:: cout << "__________________________" << std::endl << std::endl;

    try
    {
        // in this case the bureaucrat have a grad too low to sign the form so an exception occure
        Bureaucrat b2("med", 10);
        Form f2("Cer2", 1, 100);
        f2.beSigned(b2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}