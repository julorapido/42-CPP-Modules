/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:18:17 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/24 16:11:49 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

// Constructors
Fixed::Fixed(void): _fp_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}
// Copy Constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

// Int && Float Constructor 
Fixed::Fixed(const float f)
{
	std::cout << "Float Constructor Called" << std::endl;
	this->_fp_value = roundf(f * (1 << this->_fract_bits));
}
Fixed::Fixed(const int i)
{
	std::cout << "Int Constructor Called" << std::endl;
	this->_fp_value = i << this->_fract_bits;
}

// Deconstructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// Operator
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assisgnment operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();

	return *this;	
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}


// Public Methods
// Getter
int	Fixed::getRawBits(void)const
{ return (this->_fp_value); }

void	Fixed::setRawBits(int const raw)
{ this->_fp_value = raw; }

float Fixed::toFloat(void)const
{ return ((float)this->_fp_value / (float)(1 << this->_fract_bits)); }

int Fixed::toInt(void)const
{ return (this->_fp_value >> this->_fract_bits); }
