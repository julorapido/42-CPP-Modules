/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:31:36 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 15:29:52 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP
# include <iostream>

class Weapon{

	private:
		std::string	type;
	public:
		Weapon(std::string t);
		const std::string &getType();
		void	setType(std::string new_string);
};

#endif
