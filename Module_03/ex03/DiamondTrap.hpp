/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:02 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/27 18:08:30 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DiamondTrap_HPP

# define DiamondTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

using namespace std;

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap(std::string name);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &);
        void            attack(const std::string &target);
        void            highFivesGuys(void);
        void            whoAmI(void);
    private:
	    std::string     _name;
		unsigned int    _hit_pts;
		unsigned int    _energy_pts;
		unsigned int    _attack_dmg;
};

#endif