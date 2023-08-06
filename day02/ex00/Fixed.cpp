#include "Fixed.hpp"

const int Fixed::frac_b = 8;

Fixed::Fixed(): fixed_p(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixed_p);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    fixed_p = raw;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; // we use here assignment operator
}

Fixed   &Fixed::operator = (const Fixed &source){

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
    {
        this->fixed_p = source.getRawBits();
    }
    return (*this);
}
