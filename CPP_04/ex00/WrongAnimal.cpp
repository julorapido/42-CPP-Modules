/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:39 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 13:18:43 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "AnyWrong";
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "bye" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	if (this->type == "WrongCat")
		std::cout << "\tWrongMiaou!" << std::endl;
	else
		std::cout << "\tDefaultWrongAnimalSound!" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->type = rhs.type;
	return (*this);
}
WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
