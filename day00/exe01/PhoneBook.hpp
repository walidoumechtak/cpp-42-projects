#include "Contact.hpp"

class PhoneBook
{

private:
    friend int main();
    Contact contact[8];
    static int cpt;

public:
    PhoneBook();
    PhoneBook(Contact contact[8]);
    ~PhoneBook();
    void    add_to_contact(Contact c);
    Contact    get_one_contact(int i);
    int get_cpt();
};