/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:02 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/17 14:29:25 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DiamondTrap_HPP

# define DiamondTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public FragTrap,  public ScavTrap
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
        std::string _name;  // DiamondTrap's own name attribute
};

#endif