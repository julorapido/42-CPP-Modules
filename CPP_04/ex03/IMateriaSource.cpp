/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:03 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 13:19:18 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for(int i = 0; i < this->_inventory_size ; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < this->_inventory_size; i++)
		if(this->_inventory[i])
			delete this->_inventory[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & ref)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (ref._inventory[i])
			this->_inventory[i] = (ref._inventory[i])->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while(i < this->_inventory_size && this->_inventory[i] != NULL)
	{
		i++;
	}
	if (i >= this->_inventory_size)
	{
		std::cout << "\033[31m Can't learn more than "<< this->_inventory_size << " Materia \033[0m" << std::endl;
		std::cout << "\033[31m freeing "<< m->getType() << "... \033[0m" << std::endl;
		delete(m);
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << "\033[33mMateria " << m->getType() << " learned \033[0m\n";
}

AMateria		*MateriaSource::createMateria(const std::string &m)
{
	int i = 0;

	while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != m 
		&& i < this->_inventory_size)
		i++;
	if (i >= this->_inventory_size || !(this->_inventory)[i])
	{
		std::cout << m << " materia does not exit\n" << std::endl;
		return (NULL);
	}
	std::cout << "\033[33m => Materia '" << m << "' created <=\033[0m\n";
	return (((this->_inventory)[i])->clone());
}
