/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:51:59 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/27 16:52:00 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	this->_guarding_gate = false;
    this->_name = std::string("SC4V-TRAP");
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    this->_hit_pts = copy._hit_pts;
	this->_energy_pts = copy._energy_pts;
	this->_attack_dmg = copy._attack_dmg;
	this->_guarding_gate = copy._guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	this->_guarding_gate = false;
    this->_name = name;
	std::cout << "\033[34mScavTrap Constructor for name: '" << this->_name << "' called.\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "-1 ScavTrap (destroyed)" << std::endl;
}

// Overloaded Operator = = =
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "\033[34mScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage! \033[0m" << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mScavTrap " << this->_name << " cant attack " << target << ", (not enought EP).\033[0m" << std::endl;
	else
		std::cout << "\033[31mScavTrap " << this->_name << " cant attack " << target << ", (not enough HP).\033[0m" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_guarding_gate == false)
	{
		this->_guarding_gate = true;
		std::cout << "\033[32mScavTrap " << this->_name << " now guarding the gate.\033[0m" << std::endl;
	}
	else
		std::cout << "\033[33mScavTrap " << this->_name << " is alr guarding the gate.\033[0m" << std::endl;
}
