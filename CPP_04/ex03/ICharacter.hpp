/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:26 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 13:50:52 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"


class AMateria;

// INTERFACE CHARACTER
class ICharacter
{
	public:
		virtual 		~ICharacter(){};
		virtual const	std::string &getName() const = 0;
		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;

};


// "public" CHARACTER
class Character: public ICharacter
{
	protected:
		static const int	_inventorySize = 4;
		AMateria 			*_inventory[_inventorySize];
		std::string			_name;

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &src);
		Character &operator=(Character const & ref);

		virtual				~Character();

		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

};

#endif