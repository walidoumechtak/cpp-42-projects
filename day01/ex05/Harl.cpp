#include "Harl.hpp"
#include <cctype>

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string COMP[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    typedef void (Harl::*c)();
    c add_comp[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    Harl obj;
    int i = 0;
    while (COMP[i] != level)
    {
        i++;
        if (i == 4)
        {
            std::cerr << "The level you entred is not exist!!" << std::endl;
            return;
        }
    }
    (obj.*add_comp[i])();
}

Harl::Harl()
{
}

Harl::~Harl()
{
}