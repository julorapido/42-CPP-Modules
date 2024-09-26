/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:01:42 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/26 14:12:24 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float sign(const Point p1, const Point p2, const Point p3)
{
	return (p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y()) - (p2.get_x() - p3.get_x()) * (p1.get_y() - p3.get_y());
}
bool bsp(const Point a, const Point b, const Point c, const Point pt)
{
	float	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = sign(pt, a, b);
	d2 = sign(pt, b, c);
	d3 = sign(pt, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
