/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:17:02 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 15:33:50 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanB{

	private:
		Weapon		*weapon;
		std::string	name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &w);
		void	attack(void);
};

