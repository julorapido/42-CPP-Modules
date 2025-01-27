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

int	main(int argc, char **argv)
{
	(void)(argc);
	(void)(argv);
	ClapTrap c1 = ClapTrap("wers");
	ClapTrap c2 = ClapTrap("weewrwer");

	// c1.attack(c2);
	c1.beRepaired(10);
	c1.beRepaired(10);	
	c1.beRepaired(10);
	c1.attack("c2");
	for(int i = 0; i < 12; i ++)
	{
		c1.attack("Le BeauJack N-");
	}
	c2.takeDamage(12);
	return (0);
}
