/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:29:20 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/10 16:58:51 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>


class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string name); // constructor
		~Zombie(void);	// destructor
		void 	announce(void);
};

#endif
