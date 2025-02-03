/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:45:01 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 12:22:22 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::TooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	{
		Bureaucrat *a = new Bureaucrat(104);
		Form *f2 = new Form(12, 40);
		Form *f3 = new Form(*f2);	
		Form *f4 = new Form("forme");
		Form *f5 = new Form("f5", 14, 103);
		
		std::cout << f4->getName() << std::endl;
		std::cout << f5->getName() << std::endl;
		std::cout << "40 VS " << f2->getRequiredGradeExec() << std::endl;
		std::cout << "103 VS " << f5->getRequiredGradeExec() << std::endl;
		std::cout << "\033[34mTesting (Fail-Signing)\033[0m" << std::endl;
		
		try
		{
			f2->beSigned(*a);
		}
		catch(Bureaucrat::TooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << f2->getName() << ": " << e.what() << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		delete f2;
		delete f3;
		delete f4;
		delete f5;
		delete a;
	}
	return 0;
}
