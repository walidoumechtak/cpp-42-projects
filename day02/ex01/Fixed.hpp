#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int fixed_p;
        static const int frac_b;
    
    public:
        Fixed();
        Fixed(const int nb);
        // Fixed(const float nb_f);
        Fixed(const Fixed &copy); // copy default constructor
        Fixed &operator = (const Fixed &source); // assignment operator
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif