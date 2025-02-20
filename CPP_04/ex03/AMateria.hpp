/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materials.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:08:19 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/29 12:06:31 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"


class ICharacter;

// INTERFACE A-MATERIAL
class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(const AMateria &src);
		AMateria(std::string const &type);
		AMateria			&operator =(const AMateria &src);

		std::string const	&getType() const;

		// virtual for [Ice & Cure]
		virtual				~AMateria();
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

};
class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &src);
		Cure	&operator =(const Cure &src);

		// those three are overriding
		~Cure();
		Cure	*clone() const;
		void	use(ICharacter &target);

};
class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &src);
		Ice		&operator =(const Ice &src);

		// those three are overriding
		~Ice();
		Ice		*clone() const;
		void	use(ICharacter &target);

};










#endif
