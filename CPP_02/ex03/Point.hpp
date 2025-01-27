/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:10:07 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/26 14:14:49 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		// Constructors
		Point(void);
		Point(const Point &p);
		Point(const float x, const float y);
		~Point(void);

		// Overloaded operator
		Point &operator=(const Point &src);

		// Get X Y
		const Fixed		&get_y(void)const;
		const Fixed		&get_x(void)const;
};

#endif
