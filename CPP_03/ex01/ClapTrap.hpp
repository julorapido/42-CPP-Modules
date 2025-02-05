/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:51:00 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/23 14:51:02 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP

# define ClapTrap_HPP

# include <iostream>


class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap &operator=(const ClapTrap &);
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        ~ClapTrap();

    private:
	    std::string     _name;
		unsigned int    _hit_pts;
		unsigned int    _energy_pts;
		unsigned int    _attack_dmg;
};
#endif