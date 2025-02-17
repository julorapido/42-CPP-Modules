/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:52:05 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/17 14:22:10 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP

# define ScavTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &);
        void            attack(const std::string &target);
        void            guardGate(void);
    private:
        bool            _guarding_gate;
};

#endif