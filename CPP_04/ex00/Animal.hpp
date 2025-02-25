/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:08:19 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 12:00:19 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP
# include <iostream>


class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const & cpy);
		Animal & operator=(Animal const & rhs);
		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
};

class Dog: public Animal
{
	public:
		Dog();
		~Dog();// override animal destructor
};


class Cat: public Animal
{
	public:
		Cat();
		~Cat(); // override animal destructor too
};
#endif
