/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:41:02 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 15:28:44 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <iostream>
using namespace std;

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

		std::string		getName(void)const;
		unsigned int	getGrade(void)const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			setGrade(int grade);
};
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
