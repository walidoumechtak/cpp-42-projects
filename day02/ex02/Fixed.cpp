#include "Fixed.hpp"
#include <cmath>

const int Fixed::frac_b = 8;

int Fixed::getRawBits() const
{
    return (fixed_p);
}

void    Fixed::setRawBits(int const raw)
{
    fixed_p = raw;
}

// to int and to float function ----------------------------------------------------

float Fixed::toFloat(void) const
{
    return ((float)fixed_p / 256);
}

int Fixed::toInt(void) const
{
    return (fixed_p / 256);
}

Fixed::Fixed(): fixed_p(0)
{
   // std::cout << "Default constructor called" << std::endl;
}

// int constructor is called 
Fixed::Fixed(const int nb){
    int scaling;

    //std::cout << "Int constructor called" << std::endl;
    scaling = 1 << frac_b;
    fixed_p = nb * scaling;
}

// float constructor is called 
Fixed::Fixed(const float nb_f)
{
    int scaling;

   // std::cout << "Float constructor called" << std::endl;
    scaling = 1 << frac_b;
    fixed_p = roundf(nb_f * scaling);
}

Fixed::Fixed(const Fixed &obj)
{
   // std::cout << "Copy constructor called" << std::endl;
    this->fixed_p = obj.fixed_p;
}

Fixed::~Fixed()
{
   // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &source)
{
  //  std::cout << "copy assignement operator called" << std::endl;
    if (this != &source)
    {
        this->fixed_p = source.fixed_p;
    }
    return (*this);
}

Fixed Fixed::operator+(const Fixed &obj)
{
    Fixed new_o;
    new_o.setRawBits(this->fixed_p + obj.fixed_p);
    return (new_o);
}

Fixed Fixed::operator-(const Fixed &obj)
{
    Fixed new_o;
    new_o.setRawBits(this->fixed_p - obj.fixed_p);
    return (new_o) ;
}

Fixed Fixed::operator * (const Fixed &obj)
{
    Fixed new_o;
    new_o.setRawBits(this->toFloat() * obj.toFloat());
    return (new_o);
}

Fixed Fixed::operator / (const Fixed &obj)
{
    Fixed new_o;
    new_o.setRawBits(this->fixed_p >> 8 / obj.fixed_p >> 8);
    return (new_o);
}

bool Fixed::operator==(const Fixed &obj)
{
    if (this->fixed_p == obj.fixed_p)
        return (true);
    else
        return (false);
}

bool Fixed::operator > (const Fixed &obj)
{
    if (this->fixed_p > obj.fixed_p)
        return (true);
    else
        return (false);
}

bool Fixed::operator < (const Fixed &obj)
{
    if (this->fixed_p < obj.fixed_p)
        return (true);
    else
        return (false);
}

bool Fixed::operator >= (const Fixed &obj)
{
    if (this->fixed_p >= obj.fixed_p)
        return (true);
    else
        return (false);
}

bool Fixed::operator <= (const Fixed &obj)
{
    if (this->fixed_p <= obj.fixed_p)
        return (true);
    else
        return (false);
}

bool Fixed::operator != (const Fixed &obj)
{
    if (this->fixed_p != obj.fixed_p)
        return (true);
    else
        return (false);
}

// ========================== increment and decrement overloading ======================

Fixed   &Fixed::operator++() // ++obj --> pre-increment
{
   (fixed_p)++;
    return *this;
}

Fixed Fixed::operator ++ (int) // obj++  --> post-increment
{
    Fixed old;
    
    old = *this;
    ++fixed_p;
    return (old);
}

Fixed   &Fixed::operator--()
{
    this->fixed_p--;
    return (*this);
}

Fixed   Fixed::operator-- (int)
{
    Fixed old;

    old = *this;
    this->fixed_p--;
    return (old);
}

// ========================== min and max static member functions ======================

 Fixed  &Fixed::min(Fixed& n1, Fixed& n2)
{
    if (n1.fixed_p < n2.fixed_p)
        return (n1);
    else
        return (n2);
}

const Fixed  &Fixed::min(const Fixed& n1, const Fixed& n2)
{
    if (n1.fixed_p < n2.fixed_p)
        return (n1);
    else
        return (n2);
}

Fixed &Fixed::max(Fixed& n1, Fixed& n2)
{
    if (n1.fixed_p < n2.fixed_p)
        return (n1);
    else
        return (n2);
}

const Fixed &Fixed::max(const Fixed& n1, const Fixed& n2)
{
    if (n1.fixed_p > n2.fixed_p)
        return (n1);
    else
        return (n2);
}

// << operator overloading ----------------------------------------------------------
std::ostream& operator<<(std::ostream & os, const Fixed &obj)
{
    float res = obj.toFloat();
    os << res;
    return (os);
}