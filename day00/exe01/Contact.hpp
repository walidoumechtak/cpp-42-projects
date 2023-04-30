#include <string>
#include <iostream>

class Contact
{
private:
    int index;
    std::string f_name;
    std::string l_name;
    std::string nick_name;
    std::string dark_sec;

public:
    Contact();
    Contact(int in, std::string fn, std::string ln, std::string nn, std::string ds);
    ~Contact();
    void    to_string(int index, std::string f_name, std::string l_name, std::string nick_name);
    int get_index();
    std::string get_f_name();
    std::string get_l_name();
    std::string get_nick_name();
    std::string get_dark_sec();
};
