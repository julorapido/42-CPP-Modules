/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:33:14 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 12:37:21 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP

# define IMATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

using namespace std;

class ICharacter;
class AMateria;


// INTEFACE MATERIAL-SOURCE
class IMateriaSource
{
	public:
		virtual				~IMateriaSource() {}
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};


class MateriaSource: public IMateriaSource
{
	protected:
		static const int	_inventory_size = 4;
		AMateria			*_inventory[_inventory_size];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource	&operator =(const MateriaSource &src);

		virtual			~MateriaSource();

		void			learnMateria(AMateria *m);
		AMateria		*createMateria(const std::string &type);
};

#endif