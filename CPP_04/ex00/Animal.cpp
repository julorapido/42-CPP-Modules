/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:50 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 12:17:36 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Any";
}
Animal::~Animal()
{
	std::cout << "bye" << std::endl;
}

void	Animal::makeSound() const
{
	if (this->type == "Cat")
		std::cout << "\tMiaou!" << std::endl;
	else if (this->type == "Dog")
		std::cout << "\twaf" << std::endl;
	else
		std::cout << "\tDefaultAnimal" << std::endl;
}

Animal::Animal(Animal const & rhs) {
    // Copy the type from the right-hand side object
    this->type = rhs.type;
}


Animal & Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	return (*this);
}
Cat::Cat(): Animal()
{
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "cat explosion" << std::endl;
}


Dog::Dog(): Animal()
{
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "dog disappears" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
