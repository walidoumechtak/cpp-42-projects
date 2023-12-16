#include "RPN.hpp"



bool parseTheExpr(std::string expr)
{
    std::string allowedChar = "0123456789+-*/ ";
    for (int i = 0; i < (int)expr.length(); i++)
    {
        if (allowedChar.find(expr.at(i)) == std::string::npos)
        {
            return false;
        }
    }
    return true;
}

void    operations(std::stack<int> &container, std::string element)
{
    int num, res, n1, n2;

    if (container.size() < 2)
        throw std::runtime_error("Error: The container dosen't have enough data!");
    n2 = container.top();
    container.pop();
    n1 = container.top();
    container.pop();
    if (element == "+")
    {
        res = n1 + n2;
        container.push(res);
    }
    else if (element == "-")
    {
        res = n1 - n2;
        container.push(res);
    }
    else if (element == "*")
    {
        res = n1 * n2;
        container.push(res);
    } 
    else if (element == "/")
    {
        if (n2 == 0)
            throw std::runtime_error("Can't devide by 0 !!!");
        res = n1 / n2;
        container.push(res);
    }
    else
    {
        num = strtod(element.c_str(), NULL);
        container.push(num);
    }
}

void proccessTheExpr(std::string &expr, std::stack<int> &container)
{
    std::string temp = expr;
    std::stringstream ss(temp);
    std::string token;
    std::stack<std::string> tokens;
    int element;

    while (getline(ss, token, ' '))
    {
        if (token.length() == 0)
            continue;
        if (isdigit(token[0]) != 0)
        {
            element = strtod(token.c_str(), NULL);
            container.push(element);
        }
        else
            operations(container, token);
    }
}

void run(char *str)
{
    std::string expr(str);
    std::stack<int> container;
    
    if (parseTheExpr(expr) == false)
        throw std::runtime_error("the argumnet is not valid << Forbiden character >>!");
    else if (expr.length() < 3)
        throw std::runtime_error("The argument yuo provide is incorrect!");
    proccessTheExpr(expr, container);
    if (container.size() > 1)
        throw std::runtime_error("The RPN failed successfuly hhh!!!");
    else if (container.size() != 0)
        std::cout << container.top() << std::endl;
}
