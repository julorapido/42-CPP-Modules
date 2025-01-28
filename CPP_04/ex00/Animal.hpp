/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:08:19 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 12:46:10 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP
# include <iostream>

using namespace std;

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		~Animal();
		Animal & operator=(Animal const & rhs);
		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
};

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
};


class Cat: public Animal
{
	public:
		Cat();
		~Cat();
};
#endif
