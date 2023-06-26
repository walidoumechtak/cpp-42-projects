#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    int index;
    std::string f_name;
    std::string l_name;
    std::string nick_name;

public:
    Contact();
    ~Contact();
};

#endif