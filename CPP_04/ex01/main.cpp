/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:06:52 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 14:58:13 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int	main(void)
{
	const Animal *a[50];
	for(int i = 0; i < 50; i++)
	{
		if (i < 25)
			a[i] =  new Cat();
		else
			a[i] = new Dog();
	}

	// test copy
	Cat *AA = new Cat(); // Create a copy of a[1]
	Cat *BB = new Cat(*AA); // Create a copy of a[1]

	// Modify a[1] data to see if AA is shallowly affected
	AA->set_brain_idea(0, "we");

	std::cout << "AA data: " << AA->get_brain_idea(0) << std::endl;
    std::cout << "a[1] data: " << BB->get_brain_idea(0) << std::endl;  // Should not be affected by a[1] change
	
	for(int i = 0; i < 50; i++)
		delete(a[i]);
	delete(AA);
	delete(BB);

	return 0;
}
