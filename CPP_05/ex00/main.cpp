/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:45:01 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 12:07:27 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *b = new Bureaucrat();
	Bureaucrat *a = new Bureaucrat("NAmed-One");
	Bureaucrat *c = new Bureaucrat(160);

	std::cout << b->getName() << std::endl;
	std::cout << a->getName() << std::endl;
	std::cout << c->getGrade() << std::endl;
	for(int i = 0; i < 2; i++)
	{
		a->decrementGrade();
	}
	for(int i = 0; i < 152; i++)
	{
		a->incrementGrade();
	}
	b->setGrade(2);
	b->incrementGrade();
	b->incrementGrade();
	b->incrementGrade();

	// test overloaded << operator
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	delete a;
	delete b;
	return 0;
}
