#include "easyfind.hpp"

void    Vector()
{
    std::vector <int> Vector;
    for (int i = 0; i < 10; i++)
        Vector.push_back(i + 1);
    
    try
    {
        easyfind(Vector, 5);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    } 
}

void List()
{
    std::list <int> List;
    for (int i = 0; i < 10; i++)
        List.push_back(i + 1);
    
    try
    {
        easyfind(List, 404);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    } 
}

int main(void)
{
    Vector();
    List();
}