/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:53:07 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/17 14:30:39 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

// int a = 10;
int main()
{
	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	a.attack("CloneTrap");
	// 	// for (int i = 0; i < 50; i++)
	// 	// 	a.attack("CloneTrap");
	// 	a.beRepaired(22);
	// 	a.takeDamage(21);
	// 	a.beRepaired(22);
	// 	a.guardGate();
	// 	a.guardGate();
	// 	b.attack("Savage-clone");
	// 	b.takeDamage(101);
	// 	b.takeDamage(15);
	// 	b.attack("ScavTrap-clone");
	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// }
	// std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	// {
	// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	// 	FragTrap a;
	// 	FragTrap b("Chadd");

	// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
	// 	a.highFivesGuys();
	// 	a.attack("some random dude");
	// 	a.takeDamage(101);
	// 	a.takeDamage(1);
	// 	a.attack("some random dude");
	// 	b.highFivesGuys();
	// 	// for(int i = 0; i < 101; i++)
	// 	// 	b.attack("FragTrap-clone");
	// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	// }
	std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		DiamondTrap a;
		DiamondTrap b("Giga Chadd");
		DiamondTrap c(a);

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}
