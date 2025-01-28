/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:50 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 12:54:04 by jsaintho         ###   ########.fr       */
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



Animal & Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	return (*this);
}
Cat::Cat(): Animal()
{
	this->type = "Cat";
}


Dog::Dog(): Animal()
{
	this->type = "Dog";
}

std::string	Animal::getType() const
{
	return (this->type);
}
