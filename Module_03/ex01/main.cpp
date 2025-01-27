/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:53:07 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/27 12:53:57 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(int argc, char **argv)
{
	(void)(argc);
	(void)(argv);
	ClapTrap c1 = ClapTrap("wers");
	ClapTrap c2 = ClapTrap("weewrwer");
	ScavTrap scav = ScavTrap("SCAV_1");
	ScavTrap scav2 = ScavTrap("SCAV_2");

	ScavTrap scav3 = (scav);

	// c1.attack(c2);
	c1.beRepaired(10);
	scav.beRepaired(10);
	c1.attack("c2");
	for(int i = 0; i < 12; i ++)
	{
		scav.attack("Le BeauJack N-");
	}
	for(int j = 0; j < 3; j ++)
		scav.guardGate();
	c2.takeDamage(12);
	return (0);
}
