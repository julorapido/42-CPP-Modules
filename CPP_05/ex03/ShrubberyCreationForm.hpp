/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:23:22 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 15:47:45 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// classes
class Bureaucrat;
class From;

class ShrubberyCreationForm: public Form
{
	private:
		const std::string _target;
		// moved the default Constructor to private because subject asks for orthodox canonical form
		// but also asks for the Forms to only have one constructor that takes one argument
		ShrubberyCreationForm(void);
	public:
		// Constructors
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		// Public Methods
		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
#endif
