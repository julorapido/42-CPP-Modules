/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:53:07 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/23 14:53:09 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	if (name.empty())
		this->_name = std::string("CL4P-TP");
	else
		this->_name = (name);
    std::cout << "ClapTrap["<< name << "] appeared!" << std::endl;
	this->_energy_pts = 10; // 10 MANA
	this->_attack_dmg = 0; // 0 DAMAGE
	this->_hit_pts = 10; // 10 HP
}

ClapTrap::~ClapTrap()
{
    std::cout << "-1 ClapTrap (destroyed)" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copying clatraps 1=1" << std::endl;
	if (this == &src)
		return *this;
	else
	{
		this->_energy_pts = src._energy_pts;
		this->_attack_dmg = src._attack_dmg;
		this->_hit_pts = src._hit_pts;
	}
	return *this;	
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "\033[33mClapTrap " << this->_name << " attacks " << target << ", causing [" << this->_attack_dmg << " pts] of damage! \033[0m" << std::endl;
		this->_energy_pts--;
	}
	else
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hit_pts < amount)
	{
		this->_hit_pts = 0;
		std::cout << "\033[31mClapTrap " << this->_name << " took -" << amount << "dmg \033[0m" << std::endl;
		std::cout << "\033[32mClapTrap " << this->_name << " died :/ \033[0m" << std::endl;
	}else
	{
		std::cout << "\033[31mClapTrap " << this->_name << " took -" << amount << "dmg \033[0m" << std::endl;
    	this->_hit_pts -= (amount);
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts == 0)
		std::cout << "\033[33m ClapTrap " << this->_name << " is not able to repair himself, because he has no energy points left.\033[0m" << std::endl;
	else
	{
		this->_hit_pts += (amount);
		std::cout << "\033[32m ClapTrap " << this->_name << " regained " << amount << "HP! (and is now "<< this->_hit_pts << "hp)\033[0m" << std::endl;
	}
}
