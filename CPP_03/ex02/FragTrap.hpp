/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:52:05 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 15:24:42 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP

# define FragTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &);
        void            attack(const std::string &target);
        void            guardGate(void);
        void            highFivesGuys(void);
    private:
	    // std::string     _name;
		// unsigned int    _hit_pts;
		// unsigned int    _energy_pts;
		// unsigned int    _attack_dmg;
};

#endif