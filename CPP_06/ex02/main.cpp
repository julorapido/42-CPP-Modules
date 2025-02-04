/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:47:36 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 16:32:13 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"


int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

		
	Base *b = Base::generate();

	std::cout << "----- GENERATING ------" << std::endl;
	(*b).identify(b);
	(*b).identify(*b);

	delete b;
	return 0;
}
