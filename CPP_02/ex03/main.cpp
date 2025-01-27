/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:07:37 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/26 14:21:26 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	{
		const Point a;
		const Point b(10.0, 0.0);
		const Point c(0.0, 10.0);
		const Point point(1.0, 1.0);

		std::cout << "Is point (x: " << point.get_x() << " y: " << point.get_y() << ") inside the triangle : \n" <<
			"\ta( x= " << a.get_x() << "\t\ty= " << a.get_y() << "\t)\n" <<
			"\tb( x= " << b.get_x() << "\ty= " << b.get_y() << "\t)\n" <<
			"\tc( x= " << c.get_x() << "\t\ty= " << c.get_y() << "\t)\n" << std::endl;
		
		std::cout << (bsp(a, b, c, point) ? "\033[32mTRUE\033[0m" : "\033[31mFALSE\033[0m") << std::endl;	
	}
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
	{
		Point a(-1.5, -1.5);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(8.5, -9);

		std::cout << "Is point(x: " << point.get_x() << " y: " << point.get_y() << ") inside the triangle : \n" <<
			"\ta( x= " << a.get_x() << "\ty= " << a.get_y() << "\t)\n" <<
			"\tb( x= " << b.get_x() << "\ty= " << b.get_y() << "\t)\n" <<
			"\tc( x= " << c.get_x() << "\ty= " << c.get_y() << "\t)\n" << std::endl;
		
		std::cout << (bsp(a, b, c, point) ? "\033[32mTRUE\033[0m" : "\033[31mFALSE\033[0m") << std::endl;	
	}
	return (0);
}
