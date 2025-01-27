/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:45:00 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 15:36:11 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : weapon(w)
{
	this->name = n;
	// this->weapon = w;
	std::cout << "[HumanA] " << this->name << "created, WEAPON : " << w.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "[HumanA] " << this->name << " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name <<" attacks with his " << this->weapon.getType() << std::endl;
}

