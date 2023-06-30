#include "PhoneBook.hpp"

int  PhoneBook::cpt = 0;

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::get_cpt()
{
    return (cpt);
}

void    PhoneBook::add_to_contact(Contact c)
{
    contact[cpt] = c;
    cpt++;
    if (cpt == 8)
        cpt = 0;
}

Contact PhoneBook::get_one_contact(int  i)
{
    return (contact[i]);
}

