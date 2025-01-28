/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:15:33 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 13:18:09 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongAnimal_HPP

# define WRONGWrongAnimal_HPP

# include <iostream>

using namespace std;

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal & operator=(WrongAnimal const & rhs);
		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
};

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
};
#endif
