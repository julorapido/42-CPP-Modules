/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:06:52 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/20 12:25:38 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << a->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	c->makeSound(); //will output the wrongcat sound!
	a->makeSound();

	delete j;
	delete i;

	delete meta;

	delete a;
	delete c;
	return 0;
}
