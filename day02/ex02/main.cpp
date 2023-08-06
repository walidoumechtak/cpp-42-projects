#include "Fixed.hpp"

/**
 * main - the start of every program
 * Return: allways 0 (Success)
*/

int main(void)
{
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;


    // Fixed   c(Fixed(2) + Fixed(2.2f));

    // std::cout << "c --> " << c << std::endl;
    // return 0;

    Fixed a(1);
    a++;
    std::cout << a << std::endl;
}