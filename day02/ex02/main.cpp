/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:29:46 by woumecht          #+#    #+#             */
/*   Updated: 2023/08/21 14:33:51 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main(void)
{
    // ====================== Subject Test
    
        // Fixed a;
        // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        // std::cout << a << std::endl;
        // std::cout << ++a << std::endl;
        // std::cout << a << std::endl;
        // std::cout << a++ << std::endl;
        // std::cout << a << std::endl;
        // std::cout << b << std::endl;
        // std::cout << Fixed::max( a, b ) << std::endl;

    // ====================== My Test
    
     /*   Fixed a(1);
        Fixed b(1.2f);

        if (a == b)
            std::cout << "Not equal" << std::endl;
        if (a > b)
            std::cout << "a > b" << std::endl;
        if (a < b)
            std::cout << "a < b" << std::endl;
        if (a != b)
            std::cout << "a != b" << std::endl;
        if (a >= b)
            std::cout << "a >= b" << std::endl;
        if (a <= b)
            std::cout << "a <= b" << std::endl;
       */

	// Fixed a;
    Fixed temp = Fixed(1.222f) * Fixed(3);
    Fixed b(temp);
	// a.min(15, 8);
	return 0;
}
