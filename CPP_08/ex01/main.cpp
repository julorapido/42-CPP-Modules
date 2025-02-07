/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:42:04 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/07 15:32:23 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SZ 12000

int	main(void)
{
	if(SZ > INT_MAX)
		return 0;
	{
		Span s = Span(SZ);
			srand(time(0));
		// test max capacity 
		for(int i = 0; i < SZ + 3; i ++)
		{
			int random = 1+ (rand() % (SZ * 30 ));
			s.addNumber(random);
		}
		s.showNumbers();

		std::cout << "\033[32m Shortest Span: " << s.shortestSpan() << "\033[0m"  << std::endl;
		std::cout << "\033[34m Longest Span: " << s.longestSpan() << "\033[0m"  << std::endl;
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return (0);
}
