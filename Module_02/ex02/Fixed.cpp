/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:18:21 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/25 14:40:18 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

// Constructors
Fixed::Fixed(void): _fp_value(0)
{	std::cout << "Default Constructor called" << std::endl;	}
Fixed::Fixed(const float f)
{	this->_fp_value = roundf(f * (1 << this->_fract_bits));	}
Fixed::Fixed(const int i)
{	this->_fp_value = i << this->_fract_bits;	}
Fixed::Fixed(const Fixed &copy)
{	*this = copy;	}

// Deconstructor
Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}


// Operators
Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assisgnment operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();

	return *this;	
}
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}


// Comparison Operators
bool	Fixed::operator>(Fixed fixed) const
	{return (this->toFloat() > fixed.toFloat());	}

bool	Fixed::operator<(Fixed fixed) const
	{return (this->toFloat() < fixed.toFloat());	}

bool	Fixed::operator>=(Fixed fixed) const
	{return (this->toFloat() >= fixed.toFloat());	}

bool	Fixed::operator<=(Fixed fixed) const
	{return (this->toFloat() <= fixed.toFloat());	}

bool	Fixed::operator==(Fixed fixed) const
	{return (this->toFloat() == fixed.toFloat());	}

bool	Fixed::operator!=(Fixed fixed) const
	{return (this->toFloat() != fixed.toFloat());	}


// Arithmetic Operators
float	Fixed::operator+(Fixed fixed) const
	{return (this->toFloat() + fixed.toFloat());	}

float	Fixed::operator-(Fixed fixed) const
	{return (this->toFloat() - fixed.toFloat());	}

float	Fixed::operator*(Fixed fixed) const
	{return (this->toFloat() * fixed.toFloat());	}

float	Fixed::operator/(Fixed fixed) const
	{return (this->toFloat() / fixed.toFloat());	}

// [Pre/Post]-increment Operators
Fixed	Fixed::operator++()
	{this->_fp_value++;			return (*this);		}
Fixed	Fixed::operator--()
	{this->_fp_value--; 		return (*this);		}
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;

	++this->_fp_value;
	return (tmp);
}
Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;

	--this->_fp_value;
	return (tmp);
}

// Public Methods
// Getter
int				Fixed::getRawBits(void)const
	{return (this->_fp_value); }

void			Fixed::setRawBits(int const raw)
	{this->_fp_value = raw; }

float 			Fixed::toFloat(void)const
	{return ((float)this->_fp_value / (float)(1 << this->_fract_bits));}

int 			Fixed::toInt(void)const
	{return (this->_fp_value >> this->_fract_bits); }

Fixed			&Fixed::min(Fixed &first, Fixed &second)
	{return (first.toFloat() <= second.toFloat() ? first : second);}

const Fixed		&Fixed::min(const Fixed &first, const Fixed &second)
	{return (first.toFloat() <= second.toFloat() ? first : second);}

Fixed			&Fixed::max(Fixed &first, Fixed &second)
	{return (first.toFloat() >= second.toFloat() ? first : second);}

const Fixed		&Fixed::max(const Fixed &first, const Fixed &second)
	{return (first.toFloat() >= second.toFloat() ? first : second);}
