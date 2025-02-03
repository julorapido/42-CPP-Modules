/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:23:22 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 14:28:07 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// classes
class Bureaucrat;
class From;

class RobotomyRequestForm: public Form
{
	private:
		const std::string _target;
		// moved the default Constructor to private because subject asks for orthodox canonical form
		// but also asks for the Forms to only have one constructor that takes one argument
		RobotomyRequestForm(void);
	public:
		// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		// Public Methods
		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);
#endif
