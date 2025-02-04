/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:45:07 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 16:26:44 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

Base::~Base()
{
    std::cout << "oof" << std::endl;
}

Base    *Base::generate(void)
{
    // randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
    int r = rand() % 3;  // Random number between 0 and 2
    switch (r)
    {
        case 0:
            return (static_cast<Base *>(new A()));
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}
void Base::identify(Base* p)
{

	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void Base::identify(Base& p)
{
	try
	{
		if (dynamic_cast<A *>(&p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

