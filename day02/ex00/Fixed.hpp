/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:24:53 by woumecht          #+#    #+#             */
/*   Updated: 2023/08/08 10:28:30 by woumecht         ###   ########.fr       */
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
        Fixed(const Fixed &copy); // copy default constructor
        Fixed &operator = (const Fixed &source); // assignment operator
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif