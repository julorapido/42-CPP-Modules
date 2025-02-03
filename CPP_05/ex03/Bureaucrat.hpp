/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:41:02 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 16:59:31 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

using namespace std;

class Form;

class Bureaucrat
{
	private:
		std::string	_name;
		int		_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string const &n);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat(unsigned int n);

		std::string		getName(void)const;
		unsigned int	getGrade(void)const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			setGrade(int grade);
		void			executeForm(Form const & form);
		void			signForm(Form &form);

	class TooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too high (< 1)!";
			}
	};

	class TooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too low (> 150)!";
			}
	};
};
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
