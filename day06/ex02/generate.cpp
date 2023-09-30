#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>

Base *generate(void)
{
    Base *res = NULL;

    srand(time(NULL));
    int rd = rand() % 3;
    rd++;
    switch (rd)
    {
    case 1:
        res = new A();
        break;
    case 2:
        res = new B();
        break;
    case 3:
        res = new C();
        break;
    default:
        break;
    }
    return (res);
}