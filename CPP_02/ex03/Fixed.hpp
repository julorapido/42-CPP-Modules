/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:06:24 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/25 15:06:47 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int				_fp_value;
		static const int _fract_bits;

	public:
		// Constructors
			Fixed(const int i);
			Fixed(const float f);
			Fixed(const Fixed &fixed);
			Fixed(void);
		// Destructor
			~Fixed();

		// Overloaded Operators
			Fixed & operator = (const Fixed &fixed);
		
			// Comparison operators
			bool operator>(Fixed fixed)const;
			bool operator<(Fixed fixed)const;
			bool operator>=(Fixed fixed)const;
			bool operator<=(Fixed fixed)const;
			bool operator!=(Fixed fixed)const;
			bool operator==(Fixed fixed)const;


			// Arithmetic operators
			float operator+(Fixed fixed)const;
			float operator-(Fixed fixed)const;
			float operator*(Fixed fixed)const;
			float operator/(Fixed fixed)const;

			// Pre-Post operators
			Fixed operator++();
			Fixed operator--();
			Fixed operator++(int);
			Fixed operator--(int);

		// Public Methods
			float toFloat(void)const;
			int toInt(void)const;
			static Fixed &min(Fixed &first, Fixed &second);
			static const Fixed &min(Fixed const &first, Fixed const &second);
			static Fixed &max(Fixed &first, Fixed &second);
			static const Fixed &max(Fixed const &first, const Fixed &second);

		// Getter Setter
			int getRawBits(void)const;
			void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
