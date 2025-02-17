/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:50:51 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/17 14:29:46 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap"), ScavTrap()
{
	this->_name = "defaultDT";
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy),  FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	_hit_pts = FragTrap::_hit_pts;     // Set hit points from FragTrap
	_energy_pts = ScavTrap::_energy_pts; // Set energy points from ScavTrap
	_attack_dmg = FragTrap::_attack_dmg; // Set attack damage from FragTrap
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
	ScavTrap::attack(target);  // Calls the attack method from ScavTrap
}

void	DiamondTrap::highFivesGuys(void)
{
	std::cout << "\033[32mDiamondTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go \033[0m" << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap, my name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}