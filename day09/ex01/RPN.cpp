#include "RPN.hpp"

bool parseTheExpr(std::string expr)
{
    std::string allowedChar = "0123456789+-*/";
    for (int i = 0; i < (int)expr.length(); i++)
    {
        if (allowedChar.find(expr.at(i)) == std::string::npos)
            return false;
    }
    return true;
}

void    operation()

void proccessTheExpr(std::string &expr)
{
    std::stack<int> container;
    std::string temp = expr;
    size_t  pos;
    std::string element;
    int num;
    int n1, n2;
    for (;;)
    {
        pos = temp.find(" ");
        if (pos == std::string::npos)
        {
            if (temp.length() == 0)
                break;
        }
        else
        {
            element = temp.substr(0, pos);
            temp = temp.substr(pos);
            if (element == "+")
            {
                if (container.size() < 2)
                    throw std::runtime_error("Error: The container dosen't have enough data!");
                n1 = container.top();
                container.pop();
                n2 = container.top();
                container.pop();
            }
            else if (element == "-")
            {
                if (container.size() < 2)
                    throw std::runtime_error("Error: The container dosen't have enough data!");
            }
            else if (element == "*")
            {
                if (container.size() < 2)
                    throw std::runtime_error("Error: The container dosen't have enough data!");
            }
            else if (element == "/")
            {
                if (container.size() < 2)
                    throw std::runtime_error("Error: The container dosen't have enough data!");
            }
            else
            {
                num = strtod(element.c_str(), NULL);
                container.push(num);
            }
        }
        if (temp.length() == 0)
            break;
    }
}

void run(char *str)
{
    std::string expr(str);

    if (parseTheExpr(expr) == false)
        throw std::runtime_error("the argumnet is not valid << Forbiden character >>!");
    proccessTheExpr(expr);
}