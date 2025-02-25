/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:08:19 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 12:19:00 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP
# include <iostream>

# include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal & operator=(Animal const & rhs);
		Animal (Animal const & rhs);
		virtual void		makeSound(void) const = 0;
		virtual std::string	getType(void) const;
};

class Dog: public Animal
{
	private:
		Brain *b;
	public:
		Dog &operator=(const Dog &src); // override equality operator (to copy Brains too)
		Dog(const Dog &copy);
		Dog();
		~Dog();
		void makeSound(void) const;// override makeSound() (since its pure virtual)
};


class Cat: public Animal
{
	private:
		Brain *b;
	public:
		void				set_brain_idea(int i, std::string s) const;
		const std::string	get_brain_idea(int i) const;
		Cat &operator=(const Cat &src);
		Cat(const Cat &copy);
		Cat();
		~Cat();
		void makeSound(void) const;
};
#endif
