#include "Fixed.hpp"
#include <cmath>
#include <stdio.h>

const int Fixed::frac_b = 8;

Fixed::Fixed(): fixed_p(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_p = nb << frac_b;
}

Fixed::Fixed(const float nb_f)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_p = roundf(nb_f * 256);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//------------------------------------  end constr and destruc ---------------------------

int Fixed::getRawBits() const
{
    return (fixed_p);
}

void    Fixed::setRawBits(int const raw)
{
    fixed_p = raw;
}

//------------------------------------  end getter and setter ---------------------------

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed   &Fixed::operator = (const Fixed &source){

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
    {
        this->fixed_p = source.getRawBits();
    }
    return (*this);
}

// to int and to float function ----------------------------------------------------

float Fixed::toFloat(void) const
{
    return ((float)fixed_p / 256);
}

int Fixed::toInt(void) const
{
    return ((fixed_p / 256));  // fixed_p >> getRawBits(); == 8
}

// << operator overloading ----------------------------------------------------------

std::ostream& operator<<(std::ostream & os, const Fixed &obj)
{
    float res = obj.toFloat();
    os << res;
    return (os);
}