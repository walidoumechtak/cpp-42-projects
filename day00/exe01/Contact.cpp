#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{  
}

Contact::Contact(int in, std::string fn, std::string ln, std::string nn, std::string ph, std::string ds):
 index(in), f_name(fn), l_name(ln), nick_name(nn), phone(ph), dark_sec(ds)
{
}

void    Contact::to_string(int index, std::string f_name, std::string l_name, std::string nick_name)
{
    std::cout << "|" << std::setw(10) << std::right  << index;
    if (f_name.length() >= 10)
        std::cout << "|" << std::setw(10) << std::right << f_name.substr(0, 9) + ".";
    else
        std::cout << "|" << std::setw(10) << std::right << f_name;
    if (l_name.length() >= 10)
        std::cout << "|" << std::setw(10) << std::right << l_name.substr(0, 9) + ".";
    else
        std::cout << "|" << std::setw(10) << std::right << l_name;
    if (nick_name.length() >= 10)
        std::cout << "|" << std::setw(10) << std::right << nick_name.substr(0, 9) + ".";
    else
        std::cout << "|" << std::setw(10) << std::right << nick_name;
    std::cout << "|" << std::endl;
}

int Contact::get_index()
{
    return (index);
}

std::string Contact::get_f_name()
{
    return (f_name);
}

std::string Contact::get_l_name()
{
    return (l_name);
}

std::string Contact::get_nick_name()
{
    return (nick_name);
}

std::string Contact::get_dark_sec()
{
    return (dark_sec);
}

std::string Contact::get_phone(){
    return (phone);
}

Contact::~Contact()
{
}