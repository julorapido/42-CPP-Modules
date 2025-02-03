/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:45:01 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 16:59:46 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "\033[34m-----------------------Constructing-----------------------\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(45);
		Form *b = new ShrubberyCreationForm("TREEEEE");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
			// thx to static_cast<Form&>
			// can execute form directly from the bureaucrat itself
			// (((ShrubberyCreationForm *)(b)))->execute(*a);
			// !
		}
		catch(Bureaucrat::TooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
		std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		Intern *z = new Intern();
		Form *b = z->MakeForm("RobotomyRequestForm", "Bender");
		Form *c = z->MakeForm("ShrubberyCreationForm", "Cristmas");
		// Form *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signForm(*c);
		std::cout << std::endl;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	}
	return 0;
}
