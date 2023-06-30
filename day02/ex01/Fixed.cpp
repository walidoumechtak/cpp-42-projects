#include "Fixed.hpp"

const int Fixed::frac_b = 8;

Fixed::Fixed(): fixed_p(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// int constructor is called 

Fixed::Fixed(const int nb){
    int scaling;
    int conv;

    scaling = 1 << frac_b; // 1 << farc_b (8)
    conv = nb * scaling;
    std::cout << "Int constructor called" << std::endl;
    std::cout << conv << std::endl;
}

// float constructor is called 

Fixed::Fixed(const float nb_f)
{
    std::cout << "Float constructor called" << std::endl;
    int scaling;
    float conv;

    scaling = 1 << frac_b;
    conv = nb_f * scaling;
    std::cout << conv << std::endl; 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    //*this = copy; // we use here assignment operator
    this->setRawBits(copy.fixed_p);
    // this is a pointer to the new objecte
}

Fixed   &Fixed::operator = (const Fixed &source){

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
    {
        this->fixed_p = source.getRawBits();
    }
    return (*this);
}
