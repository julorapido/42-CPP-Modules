/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:26 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 15:37:24 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
using namespace std;

// INTERFACE CHARACTER
class ICharacter
{
	protected:
		/* PROTECTED Constructors & Destructors & Operator */
		ICharacter(void);
		ICharacter(ICharacter const &copy);
		ICharacter const	&operator=(ICharacter const &copy);
	public:
		/* Constructors & Destructors */
		virtual	~ICharacter() {}

		/* Getters & Setters */
		virtual std::string const	&getName() const = 0;

		/* Main Member Functions */
		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};


// "public" CHARACTER
class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
	public:
		/* Constructors & Destructors */
		Character(void);
		Character(std::string const &name);
		Character(Character const &copy);
		~Character(void);

		/* Basic Operators */
		Character const	&operator=(Character const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		void				setName(std::string const &name);

		/* Main Member Functions */
		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
		int 			inInventory(AMateria *m);
};

#endif