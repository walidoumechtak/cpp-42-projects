#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_p;
        static const int frac_b;
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb_f);
        ~Fixed();
        Fixed(const Fixed& obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
        Fixed &operator= (const Fixed &source);
        Fixed operator+ (const Fixed &obj);
        Fixed operator- (const Fixed &obj);
        Fixed operator* (const Fixed &obj);
        Fixed operator/ (const Fixed &obj);
        bool operator== (const Fixed &obj);
        bool operator > (const Fixed &obj);
        bool operator < (const Fixed &obj);
        bool operator >= (const Fixed &obj);
        bool operator <= (const Fixed &obj);
        bool operator != (const Fixed &obj);
        Fixed &operator ++ ();     
        Fixed operator ++ (int);
        Fixed &operator -- ();
        Fixed operator -- (int);
        static const Fixed &min(const Fixed& n1, const Fixed& n2);
        static const Fixed &max(const Fixed& n1, const Fixed& n2);
        static Fixed &min(Fixed& n1, Fixed& n2);
        static Fixed &max(Fixed& n1, Fixed& n2);
};

std::ostream& operator<<(std::ostream & os, const Fixed &obj);

#endif