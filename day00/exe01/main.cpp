#include "PhoneBook.hpp" 
#include <cctype>
#include <cstdlib>

int is_all_digit(std::string str)
{
    int i = 0;
    int len = str.length();

    if (len == 0)
        return (0);
    while (i < len)
    {
        if (!isdigit(str[i]) || str[i] == '\n')
            return (0);
        i++;
    }
    return (1);
}

void    ft_search(PhoneBook pb)
{
    Contact c;
    std::string input_index;
    int index;
    int i;

    i = 0;
    while (i < pb.get_cpt())
    {
        c = pb.get_one_contact(i);
        c.to_string(c.get_index(), c.get_f_name(), c.get_l_name(), c.get_nick_name());
        i++;
    }
    std::cout << "Search (Enter an index): " << std::endl;
    getline(std::cin, input_index);
    if (is_all_digit(input_index) == 0)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    index = stoi(input_index);
    i = 0;
    while (i < pb.get_cpt())
    {
        if (c.get_index() == index)
        {
            std::cout << "index: " << c.get_index() << std::endl;
            std::cout << "First Name: " << c.get_f_name() << std::endl;
            std::cout << "Last Name: " << c.get_l_name() << std::endl;
            std::cout << "Nick Name: " << c.get_nick_name() << std::endl;
            return;
        }
        else
        {
            std::cout << "Oops we couldn't find data with your index" << std::endl;
            return;
        }
        i++;
    }
}

void    transform_string(std::string &str)
{
    str = str.substr(0, 10);
    str[9] = '.';
}

int main()
{
    PhoneBook   pb;
    std::string  str;
    static int  in = 1;
    std::string f_n;
    std::string l_n;
    std::string nick_n;
    std::string dark_s;
    std::string phone;
   
    while (1)
    {   
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "| Enter one of three commands the program only accepts 'ADD', 'SEARCH' and 'EXIT' : |" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::getline(std::cin, str);
        if (str == "ADD")
        {
            std::cout << "First name : " << std::endl;
            std::getline(std::cin, f_n);
            if (f_n.length() > 10)
                transform_string(f_n);
            std::cout << "Last name : " << std::endl;
            std::getline(std::cin, l_n);
            if (l_n.length() > 10)
                transform_string(l_n);
            std::cout << "Nick name : " << std::endl;
            std::getline(std::cin, nick_n);
            if (nick_n.length() > 10)
                transform_string(nick_n);
            std::cout << "enter the phone number : " << std::endl;
            std::getline(std::cin, phone);
            if (phone.length() > 10)
                transform_string(phone);
            std::cout << "enter the dark secret : " << std::endl;
            std::getline(std::cin, dark_s);
            if (dark_s.length() > 10)
                transform_string(dark_s);
            pb.add_to_contact(Contact(in, f_n, l_n, nick_n, phone, dark_s));
            in++;
        }
        else if (str == "SEARCH") 
            ft_search(pb);
        else if (str == "EXIT")
            break;
    }
    return (0);
}