/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:46:24 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/07 15:22:47 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
	std::cout << "- Span created. (vec<int>[" << n << "] reserved)" << std::endl;
	this->N = n;
	this->vec.reserve(n);
}

Span::Span(const Span & copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &src)
{
	this->vec.reserve(src.vec.capacity());
	this->vec = src.vec;
	return *this;
}

Span::~Span()
{
	std::cout << "- Span destroyed." << std::endl;
	
}
void Span::addNumber(int n)
{
	// std::cout << "pusing v" << this->vec.size() << "  CAPACITY:" << this->vec.capacity() << std::endl;
	try
	{
		if(this->vec.size() >= this->vec.capacity())
		{
			throw FullException();	
		}
		else
		{
			this->vec.push_back(n);
		}
	}catch(FullException e)
	{
		std::cout << e.what() << std::endl;
	}

}

void	Span::showNumbers(void)
{
	std::cout << "vec" << "[" << this->N << "]" << ": {" ;
    for (std::vector<int>::iterator it = this->vec.begin(); 
		it != this->vec.end(); ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

int	Span::shortestSpan(void)
{
	if (this->vec.size() <= 1)
	{
		throw NoSpanException();
		return - 1;
	}
	int	sp = (INT_MAX);
    for (std::vector<int>::iterator it = this->vec.begin(); 
		it != this->vec.end(); ++it)
	{
		if(abs(*(it + 1) - *it ) > 0)
			if(abs(*(it + 1 )- *it )< sp )
				sp = abs(*(it + 1) - (*it));
	}
	return (sp);
}

int	Span::longestSpan(void)
{
	if (this->vec.size() <= 1)
	{
		throw NoSpanException();
		return -1;
	}
	int	sp = (INT_MIN);
    for (std::vector<int>::iterator it = this->vec.begin(); 
		it != this->vec.end(); ++it)
	{
		if(abs(*(it + 1 )- *it ) > sp )
			sp = abs(*(it + 1) - (*it));
	}
	return (sp);
}
