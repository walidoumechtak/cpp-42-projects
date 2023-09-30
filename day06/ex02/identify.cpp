#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

void    identify(Base *p)
{
    A *a = dynamic_cast<A*> (p);
    B *b = dynamic_cast<B*> (p);
    C *c = dynamic_cast<C*> (p);

    if (a)
        std::cout << "A" << std::endl;
    else if (b)
        std::cout << "B" << std::endl;
    else if (c)
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    int bools[3];

    bools[0] = 1;
    bools[1] = 2;
    bools[2] = 3;

    try
    {
        A &a = dynamic_cast<A&> (p);
        (void)a;
    }
    catch (std::exception &e)
    {
        bools[0] = -1;
    }
    // ========================================
    try
    {
        B &b = dynamic_cast<B&> (p);
        (void)b;
    }
    catch (std::exception&)
    {
        bools[1] = -1;
    }
    // ========================================
    try
    {
        C &c = dynamic_cast<C&> (p);
        (void)c;
    }
    catch (std::exception&)
    {
        bools[2] = -1;
    }
    // ========================================
    
    for (int i = 0; i < 3; i++)
    {
        switch (bools[i])
        {
        case 1:
            std::cout << "A" << std::endl;
            return;
        case 2:
            std::cout << "B" << std::endl;
            return;
        case 3:
            std::cout << "C" << std::endl;
            return;
        default:
            break;
        }
    }
}