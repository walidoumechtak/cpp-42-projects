#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *ptr = generate();
    identify(ptr);
    delete ptr;
  
    std::cout << "=========================" << std::endl;

    C c = C();
    Base &ref = c;
    identify(ref);
    return (0);
}