/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:30:06 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 14:07:47 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// multiple allocation new[N] Zombies
Zombie	*zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*horde = zombieHorde(10, "gauthier");	

	for(int i = 0; i < 10; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}
