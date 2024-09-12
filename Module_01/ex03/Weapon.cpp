/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:33:17 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 15:25:44 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t)
{
	this->type = t;
}

const std::string &Weapon::getType()
{
	const std::string &ref = this->type;
	return (ref);
}

void	Weapon::setType(std::string new_name)
{
	this->type = new_name;
}
