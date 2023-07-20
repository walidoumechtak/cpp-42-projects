#include "Fixed.hpp"

/**
 * main - the start of every program
 * Return: allways 0 (Success)
*/

int main(void)
{
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // Fixed c(a + b);
    // Fixed d(c / b);
    // std::cout << "a: " << a << std::endl;
    // a++;
    // std::cout << "a: " << a << std::endl;
    // std::cout << "b: " << b << std::endl;
    // std::cout << "c: " << c << std::endl;
    // ++c;
    // std::cout << "c: " << c << std::endl;
    // std::cout << "d: " << d << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;

}