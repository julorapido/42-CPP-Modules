/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:50 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 14:54:13 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal()
{
	this->type = "Any";
}
Animal::~Animal()
{
	std::cout << "bye Animal" << std::endl;
}
Cat::~Cat()
{
	std::cout << "delete cat-brain" << std::endl;
	delete this->b;
}
Dog::~Dog()
{

	std::cout << "delete dog-brain" << std::endl;
	delete this->b;
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
	this->b = new Brain();
	if (this->b == NULL)
	{
		std::cout << "\tCat Brain allocation failed" << std::endl;
	}
}
Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	this->b = new Brain();
	if (this->b == NULL)
	{
		std::cout << "Dog Brain allocation failed" << std::endl;
	}
	// *this->b = *src.b;
	return *this;
}
Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	this->b = new Brain();
	if (this->b == NULL)
	{
		std::cout << "Cat Brain allocation failed" << std::endl;
	}
	// *this->b = *src.b;
	return *this;
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = copy;
}
Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}


void	Cat::set_brain_idea(int i, std::string idea) const
{
	this->b->setIdea(i, idea);
}
const std::string	Cat::get_brain_idea(int i) const
{
	return (this->b->getIdea(i));
}

Dog::Dog(): Animal()
{
	this->type = "Dog";
	this->b = new Brain();
	if (this->b == NULL)
	{
		std::cout << "\tDog Brain allocation failed" << std::endl;
	}
}

std::string	Animal::getType() const
{
	return (this->type);
}
