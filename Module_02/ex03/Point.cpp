/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:36:27 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/26 14:14:40 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Constructors
Point::Point(void): _x(0), _y(0)
{	/*std::cout << "Default Constructor called" << std::endl;*/	}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{	/*std::cout << "x y constructor";	*/				}

Point::Point(const Point &copy): _x(copy.get_x()), _y(copy.get_y())
{	/**this = copy;*/	}

// Destructor
Point::~Point(void)
{	/*std::cout << "Destructor called" << std::endl; */	}



// Overloaded Operators
Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return *this;
	return *this;
}

// Getter Setter
const Fixed	&Point::get_x(void)const
{	return (this->_x);	}

const Fixed	&Point::get_y(void)const
{	return (this->_y);	}



// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point)
{
	o << "_x: " << point.get_x() << " / _y: " << point.get_x() << std::endl;
	return (o);
}
