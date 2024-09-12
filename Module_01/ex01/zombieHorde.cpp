/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:34:37 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 14:02:02 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombies_arr = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombies_arr[i].set_name(name);
	return zombies_arr;
}
