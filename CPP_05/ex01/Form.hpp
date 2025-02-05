/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:10:06 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 13:51:09 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP

# define FORM_HPP
# include "Bureaucrat.hpp"


#include <iostream>


class Form
{
	private:
		const std::string   _name;
        bool                _signed;
        const unsigned int  _required_grade_sign;
	    const unsigned int  _required_grade_exec;

	public:
		Form();
		~Form();
	    Form(int sign_grade, int exec_grade);
		Form(Form const &copy);
        Form(const std::string name);
        Form(const std::string name, int sign_grade, int exec_grade);
        Form &operator=(const Form &src);
        std::string		getName(void)const;
		unsigned int	getRequiredGradeSign(void)const;
        unsigned int	getRequiredGradeExec(void)const;
        bool            getIsSignedBool(void)const;
        void            beSigned(Bureaucrat &signer);


    //Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
// std::ostream	&operator<<(std::ostream &o, Form *a);
std::ostream	&operator<<(std::ostream &o, Form *a);

#endif