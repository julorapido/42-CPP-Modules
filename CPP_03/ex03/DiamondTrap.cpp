/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:50:51 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/27 18:08:47 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap")
{
	this->_name = "defaultDT";
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
    this->_name = name;
	std::cout << "\033[34mDiamondTrap Constructor for name: '" << this->_name << "' called.\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "-1 DiamondTrap (destroyed)" << std::endl;
}

// Overloaded Operator = = =
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "\033[34mDiamondTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage! \033[0m" << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mDiamondTrap " << this->_name << " cant attack " << target << ", (not enought EP).\033[0m" << std::endl;
	else
		std::cout << "\033[31mDiamondTrap " << this->_name << " cant attack " << target << ", (not enough HP).\033[0m" << std::endl;
}

void	DiamondTrap::highFivesGuys(void)
{
	std::cout << "\033[32mDiamondTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go \033[0m" << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "Hello i am a DiamondTrap named " << this->_name <<
	" and i am originated from the ClapTrap named " << ClapTrap::_name << "." <<
	std::endl;
}