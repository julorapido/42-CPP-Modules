/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:16:08 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 13:28:12 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// classes

class Bureaucrat;

class From;

class PresidentialPardonForm: public Form
{
	private:
		const std::string _target;
		// moved the default Constructor to private because subject asks for orthodox canonical form
		// but also asks for the Forms to only have one constructor that takes one argument
		PresidentialPardonForm(void);
	public:
		// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		// Public Methods
		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);
#endif