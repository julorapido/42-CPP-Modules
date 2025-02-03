/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:35:42 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 16:54:41 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "New Intern created !" << std::endl;
}

Intern::~Intern()
{
	std::cout << "New Intern created !" << std::endl;
}

Intern::Intern(const Intern &f)
{
	*this = f;
	std::cout << "New Intern copied !" << std::endl;
}

static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods
Form	*Intern::MakeForm(const std::string form_to_create, const std::string target_for_form)
{
	Form *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cout << "\033[33mIntern can not create a form called " << form_to_create << "\033[0m" << std::endl;
	return (NULL);
}


