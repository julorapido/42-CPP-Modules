/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:48:46 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 15:04:48 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA{

	private:
		Weapon		&weapon;
		std::string	name;
	public:
		HumanA(std::string name, Weapon &w);
		~HumanA(void);
		void	attack(void);
};
