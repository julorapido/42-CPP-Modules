/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:42:58 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/07 15:19:39 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

class FullException: std::exception
{
	public:
		int what()
		{
			std::cout << "Span is full !" << std::endl;
			return 0;
		}
};

class NoSpanException: std::exception
{
	public:
		int what()
		{
			std::cout << "Span non-existent" << std::endl;
			return 0;
		}
};

class Span
{
	private:
		std::vector<int>	vec;
		unsigned int		N;
		Span(); // to force it to be contructed by an unsigned int N
	public:
		~Span();
		Span(const Span & cpy);
		Span(unsigned int N);
		Span &operator=(const Span &cpy);
		void 	addNumber(int n);
		int		shortestSpan(void);
		void	showNumbers(void);
		int		longestSpan(void);
};

 #endif
