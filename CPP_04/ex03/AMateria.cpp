/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:50 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 13:12:39 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ICharacter.hpp"


AMateria::AMateria(void)
{
	this->_type = "default AMateria type.";
	std::cout << "DEFAULT-AMateria object created" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "\033[32m AMateria object created!\033[0m" << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
	std::cout << "\033[37m  AMateria object copied \033[0m " << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "\033[1m\033[37m AMateria '"<< this->_type << "' destroyed.\033[0m" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &copy)
{
	this->_type = copy._type;
	std::cout << "\033[37m AMateria Assignment Operator Called \033[0m " << std::endl;
	return (*this);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
}


std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}


// ICE-CURE
Cure::Cure(void)
	: AMateria("cure")
{}

Cure::Cure(const Cure &src)
	: AMateria(src)
{
	*this = src;
}

Cure::~Cure()
{}

Cure	&Cure::operator=(Cure const &src)
{
	(void) src;
	return *this;
}

// virtual AMateria	*Cure::clone(void) const;
Cure	*Cure::clone() const
{
	return new Cure(*this);
}
Ice	&Ice::operator =(const Ice &src)
{
	(void) src;
	return *this;
}

Ice	*Ice::clone() const
{
	return new Ice(*this);
}

Ice::Ice(void)
	: AMateria("ice")
{}
Ice::Ice(const Ice &src)
	: AMateria(src)
{}
Ice::~Ice()
{}

void	Cure::use(ICharacter &target)
{
	std::cout << " * heals " << target.getName() << "'s wounds *" << std::endl;
}
void Ice::use(ICharacter &target)
{
	std::cout << " * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
