#include "PhoneBook.hpp" 
#include <cctype>
#include <cstdlib>

int is_all_digit(std::string str)
{
    int i = 0;

    while (str.c_str()[i])
    {
        if (!isdigit(str.c_str()[i]))
            return (0);
        i++;
    }
    return (1);
}

void    ft_search(PhoneBook pb)
{
    Contact c;
    std::string s_i;
    int s_index;
    int i;

    i = 0;
    while (i < pb.get_cpt())
    {
        c = pb.get_one_contact(i);
        c.to_string(c.get_index(), c.get_f_name(), c.get_l_name(), c.get_nick_name());
        i++;
    }
    std::cout << "Search (Enter an index): " << std::endl;
    std::cin >> s_index;
    if (is_all_digit(s_i) == 0)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    s_index = atoi(s_i.c_str());
    std::cout << s_index << std::endl;
    i = 0;
    while (i < pb.get_cpt())
    {
        if (c.get_index() == s_index)
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

int main()
{
    PhoneBook   pb;
    std::string  str;
    static int  in = 1;
    std::string f_n;
    std::string l_n;
    std::string nick_n;
    std::string dark_s;

    while (1)
    {
        std::cout << "Enter one of three commands the program only accepts ADD, SEARCH and EXIT : " << std::endl;
        std::cin >> str;
        if (str == "ADD")
        {
            std::cout << "enter the first name : " << std::endl;
            std::cin >> f_n;
            std::cout << "enter the last name : " << std::endl;
            std::cin >> l_n;
            std::cout << "enter the nick name : " << std::endl;
            std::cin >> nick_n;
            std::cout << "enter the dark secret : " << std::endl;
            std::cin >> dark_s;
            // if (f_n[0] == '\0' || l_n[0] == '\0' || nick_n[0] == '\0' || dark_s[0] == '\0')
            // {
            //     printf("you shouldn't let any feilds empty\n");
            //     continue;
            // }
            pb.add_to_contact(Contact(in, f_n, l_n, nick_n, dark_s));
            in++;
        }
        else if (str == "SEARCH") 
        {
            ft_search(pb);
        }
        else if (str == "EXIT")
            break;
    }
    return (0);
}