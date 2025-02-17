/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:53:07 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/17 14:13:39 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(int argc, char **argv)
{
	(void)(argc);
	(void)(argv);
	{
		ClapTrap c1 = ClapTrap("wers");
		ClapTrap c2 = ClapTrap("weewrwer");
		ScavTrap scav = ScavTrap("SCAV_1");
		FragTrap frag = FragTrap("FRAG_1");
		FragTrap frag2 = FragTrap("FRAG_2");

		FragTrap frag3 = (frag);

		// c1.attack(c2);
		c1.beRepaired(10);
		frag.beRepaired(10);
		c1.attack("c2");
		for(int i = 0; i < 4; i ++)
		{
			frag.attack("Le BeauJack N-");
		}
		for(int j = 0; j < 3; j ++)
			frag.highFivesGuys();
		c2.takeDamage(12);
	}
	{
		std::cout << "==================== CHECK DESTRUCTION ORDER. ====================" << std::endl;
		FragTrap frag2 = FragTrap("DESTROYEY");
	}
	return (0);
}
