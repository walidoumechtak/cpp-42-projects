#include "PhoneBook.hpp" 
#include <cctype>
#include <cstdlib>
#include <string>

/**
 * is_all_digit - check if all input is a digit
 * @str: the input string
 * Return: 1 if true 0 if not
*/

int is_all_digit(std::string str)
{
    int i = 0;
    int len = str.length();

    if (len == 0)
        return (0);
    while (i < len)
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void    transform_string(std::string &str)
{
    str = str.substr(0, 10);
    str[9] = '.';
}

/**
 * ft_search - function that show all contact in the phone book
 *             and search for a desire contact
 * @pb: the phone book
*/

void    ft_search(PhoneBook pb)
{
    Contact c;
    std::string input_index;
    int index;
    int i;

    i = 0;
    while (i < pb.get_cpt()) // cpt == how many contact in our phonebook
    {
        c = pb.get_one_contact(i);
        c.to_string(c.get_index(), c.get_f_name(), c.get_l_name(), c.get_nick_name());
        i++;
    }
    std::cout << "Search (Enter an index): ";
    getline(std::cin, input_index);
    if (std::cin.eof() || std::cin.fail())
        exit(0);
    if (is_all_digit(input_index) == 0)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    index = atoi(input_index.c_str());
    i = 0;
    while (i < pb.get_cpt())
    {
        c = pb.get_one_contact(i);
        if (c.get_index() == index)
        {
            std::cout << "--------------------------" << std::endl;
            std::cout << "index: " << c.get_index() << std::endl;
            std::cout << "First Name: " << c.get_f_name() << std::endl;
            std::cout << "Last Name: " << c.get_l_name() << std::endl;
            std::cout << "Nick Name: " << c.get_nick_name() << std::endl;
            std::cout << "Phone number: " << c.get_phone() << std::endl;
            std::cout << "--------------------------" << std::endl;
            return;
        }
        i++;
    }
    std::cout << "Oops we couldn't find any data with your index !!!!!" << std::endl;
}

/**
 * check_for_all_fields - check if all fields are not empty
 * @fn: first name
 * @ln: last name
 * @nn: nick name
 * @ds: drack secret
 * @phone: phone number
 * Retrun: 0 if all fields are not empty 1 if not
*/

int check_for_all_fields(std::string fn, std::string ln, std::string nn, std::string ds, std::string phone)
{
    if (fn.empty() || ln.empty() || nn.empty() || ds.empty() || phone.empty())
        return (1);
    return (0);
}

/**
 * main - the start of the program
 * Return: allways 0
*/

int main(void)
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
        std::cout << " -----------------------------------------------------------------------------------" << std::endl;
        std::cout << "| Enter one of three commands the program only accepts 'ADD', 'SEARCH' and 'EXIT' : |" << std::endl;
        std::cout << " -----------------------------------------------------------------------------------" << std::endl;
        std::getline(std::cin, str);
        if (std::cin.eof() || std::cin.fail())
            break;
        if (str == "ADD")
        {
            std::cout << "First name : ";
            std::getline(std::cin, f_n);
            if (std::cin.eof() || std::cin.fail())
                break;
            std::cout << "Last name : ";
            std::getline(std::cin, l_n);
            if (std::cin.eof() || std::cin.fail())
                break;
            std::cout << "Nick name : ";
            std::getline(std::cin, nick_n);
            if (std::cin.eof() || std::cin.fail())
                break;
            std::cout << "enter the phone number : ";
            std::getline(std::cin, phone);
            if (std::cin.eof() || std::cin.fail())
                break;
            std::cout << "enter the dark secret : ";
            std::getline(std::cin, dark_s);
            if (std::cin.eof() || std::cin.fail())
                break;
            if (check_for_all_fields(f_n, l_n, nick_n, dark_s, phone) == 1)
            {
                std::cout << "Please fill all the fields !!!" << std::endl;
                continue;
            }
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