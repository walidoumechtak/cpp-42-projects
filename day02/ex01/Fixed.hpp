/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:29:24 by woumecht          #+#    #+#             */
/*   Updated: 2023/08/08 10:29:26 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        Fixed(const float nb_f);
        Fixed(const Fixed &copy); // copy constructor
        Fixed &operator = (const Fixed &source); // assignment operator
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream & os, const Fixed &obj);

#endif