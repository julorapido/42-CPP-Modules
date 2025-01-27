/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:07:31 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/24 16:08:20 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP 

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
		// Default Constructor
		Fixed(void);	
		// Constructor
		Fixed(const int i);
		Fixed(const float f);
		// Copy Constructor
		Fixed(const Fixed &fixed);
		~Fixed();

		// Operators
		Fixed & operator = (const Fixed &fixed);
		Fixed & operator << (const Fixed &fixed);

		// Public Methods
		int getRawBits(void)const;
		void setRawBits(int const raw);
		float toFloat(void)const;
		int toInt(void)const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
