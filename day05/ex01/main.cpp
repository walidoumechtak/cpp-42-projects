#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

    try
    {
        Bureaucrat b1("walid", 5);
        b1.signForm();
        b1.beSigned();
        b1.signForm();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
    
    std:: cout << "__________________________" << std::endl << std::endl;
    
    tyr
    {
        Bureaucrat b2("med", 10);
        Form f1("Off Form", 0, 100);
        f1.beSigned(b2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // std:: cout << "__________________________" << std::endl << std::endl;


    // std:: cout << "__________________________" << std::endl << std::endl;
    
}