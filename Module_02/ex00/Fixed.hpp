/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:22:48 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/20 12:52:17 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP 

#include <iostream>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;
	public:
		// Constructor
		Fixed();
		// Copy Constructor
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed & operator = (const Fixed &fixed);
		// Public Methods
		// Getter
		int getRawBits(void)const;
		// Setter
		void setRawBits(int const raw);
};

#endif
