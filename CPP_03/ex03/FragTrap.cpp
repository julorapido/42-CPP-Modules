/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:51:59 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/17 14:21:31 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap("FR4G-TRAP")
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    this->_hit_pts = copy._hit_pts;
	this->_energy_pts = copy._energy_pts;
	this->_attack_dmg = copy._attack_dmg;
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << "\033[34m +1FragTrap Constructor for name: '" << this->_name << "' called.\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "-1 FragTrap (destroyed)" << std::endl;
}

// Overloaded Operator = = =
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}


void	FragTrap::highFivesGuys(void)
{
	std::cout << "\033[32mFragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go \033[0m" << std::endl;
}