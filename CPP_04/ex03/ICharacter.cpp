/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:55:32 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 13:12:59 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

Character::Character()
{
	std::cout << "Default Character created." << std::endl;
    this->_name = std::string("Default_Character");
}

Character::Character(const std::string &name)
{
	std::cout << "\033[32m '" << name << "' Character created!\033[0m " << std::endl;
    this->_name = name;
    for(int i = 0; i < this->_inventorySize; i++)
	{
		this->_inventory[i] = 0;
	}
}

Character::Character(const Character &ref): _name(ref.getName() + "_copy")
{
    if(this == &ref)
        return;
    for(int i = 0; i < 4; i++)
	{
		// Deep copy!
		if ((ref._inventory)[i])
			(this->_inventory)[i] = (ref._inventory[i])->clone();
	}
    
}
Character::~Character()
{
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
    std::cout << "\033[1m\033[37m '"<< this->_name << "' destroyed. \033[0m" << std::endl;
}

Character & Character::operator=(Character const & ref)
{
	// Impossible to change name because it's constant
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (ref._inventory[i])
			this->_inventory[i] = (ref._inventory[i])->clone();
	}
	return (*this);
}


// getter
const std::string	&Character::getName() const
{
    return ((this->_name));
}

void    Character::equip(AMateria *m)
{
	int i = 0;

	if (!m)
	{
		std::cout << "\033[35m'" << this->_name << "' tried to equip nothing and it did nothing.......\033[0m\n";
		return ;
	}
	while ((this->_inventory)[i] != 0 && i < this->_inventorySize)
		i++;
	if (i >= this->_inventorySize)
	{
		std::cout << this->_name << " can't equip more than "<< this->_inventorySize << "Materia!";
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << "\033[36m'" << this->_name << "' equipped MATERIA: '" << m->getType() << "' in slot [" << i << "]\033[0m'\n";
}
void    Character::use(int idx, ICharacter &target)
{
    if(idx < 0 || idx > this->_inventorySize || this->_inventory[idx] == 0)
    {
        std::cout << "Nothing found at this index[" << idx << "]" << std::endl;
        return;
    }
    std::cout << this->_name;
    ((this->_inventory)[idx])->use(target);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_inventorySize)
		std::cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing\n";
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " cant equipp at slot " << idx << " because nothing exists.\n";
	else
	{
		AMateria *ptr = (this->_inventory)[idx];
		std::cout << this->_name << " unequipped " << ptr->getType() << " at slot "<< idx << "\n";
		(this->_inventory)[idx] = 0;
	}
}