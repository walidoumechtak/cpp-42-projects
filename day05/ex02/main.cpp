#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

    try
    {
        ShrubberyCreationForm sh1("home");
        Bureaucrat b1("walid", 1);
        sh1.beSigned(b1);
        sh1.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
    
    std:: cout << "__________________________" << std::endl << std::endl;
    


}