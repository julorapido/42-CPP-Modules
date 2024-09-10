/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:48:56 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/10 17:01:25 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// heap allocated Zombie 
Zombie	*newZombie(std::string name);

// stack non-allocated Zombie
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*z = newZombie("t");
	z->announce();
	
	randomChump("Bruno");
	delete z;
	return 0;
}
