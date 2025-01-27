/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:18:21 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 15:35:57 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n): weapon(NULL)
{
	this->name = n;
	std::cout << "[HumanB] " << this->name << " created, WEAPON : (null)." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "[HumanB] " << this->name << " destroyed." << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->name <<" attacks with his " << this->weapon->getType() << std::endl;
}

void 	HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}

