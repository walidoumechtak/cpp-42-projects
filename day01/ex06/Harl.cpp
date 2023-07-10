#include "Harl.hpp"

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

int convert_level_toint(std::string level)
{
    if (level == "DEBUG")
        return (0);
    else if (level == "INFO")
        return (1);
    else if (level == "WARNING")
        return (1);
    else if (level == "ERROR")
        return (3);
    return (-1);
}

void    Harl::complain(std::string level)
{
    int LEX;
    typedef void    (Harl::*ptr)();
    ptr func_ptr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i;

    i = 0;
    LEX = convert_level_toint(level);
    switch (LEX)
    {
    case 0:
        i = 0;
        break;
    case 1:
        i = 1;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 3;
        break;
    default:
        i = LEX;
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    Harl obj;
    while (i < 4 && i != -1)
    {
        printf("%d\n", i);
        (obj.*func_ptr[i])();
        i++;
    }
}

Harl::Harl()
{
}

Harl::~Harl()
{
}