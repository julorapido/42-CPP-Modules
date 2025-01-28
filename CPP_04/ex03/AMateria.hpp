/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:08:19 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 15:39:26 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

using namespace std;

// ABSTRACT MATERIAL
class AMateria
{
	protected:
		std::string	_type;

		/* Constructors & Destructors */
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
	public:
		/* Constructors & Destructors */
		virtual ~AMateria(void);

		/* Basic Operators */
		AMateria const	&operator=(AMateria const &copy);

		/* Getters & Setters */
		std::string const	&getType(void) const;

		/* Main Member Functions */
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;
};

// INTEFACE MATERIAL
class IMateriaSource
{
	protected:
		/* PROTECTED Constructors & Destructors */
		IMateriaSource(void);
		IMateriaSource(IMateriaSource const &copy);

		/* Basic Operators */
		IMateriaSource const	&operator=(IMateriaSource const &copy);
	public:
		/* Constructors & Destructors */
		virtual ~IMateriaSource() {}

		/* Main Member Functions */
		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};


class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_learnInventory[4];
	public:
		/* Constructors & Destructors */
		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);
		~MateriaSource(void);

		/* Basic Operators */
		MateriaSource const	&operator=(MateriaSource const &copy);

		/* Main Member Functions */
		virtual void		learnMateria(AMateria *materia);
		virtual AMateria*	createMateria(std::string const &type);
		int 				inLearnInventory(AMateria *materia);
};

class Cure: public AMateria
{
	public:
		/* Constructors & Destructors */
		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);

		/* Basic Operators */
		Cure const	&operator=(Cure const &copy);

		/* Main Member Functions */
		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};

class Ice: public AMateria
{
	public:
		/* Constructors & Destructors */
		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);

		/* Basic Operators */
		Ice const	&operator=(Ice const &copy);

		/* Main Member Functions */
		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};



#endif
