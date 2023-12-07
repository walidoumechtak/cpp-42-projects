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

void proccessTheExpr(std::string expr)
{
    std::stack<int> holder;
    
}

void run(char *str)
{
    std::string expr(str);

    if (parseTheExpr(expr) == false)
        throw std::runtime_error("the argumnet is not valid << Forbiden character >>!");
    proccessTheExpr(expr);
}